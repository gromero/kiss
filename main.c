#include <stdio.h>
#include <kissfft/kiss_fftr.h>
#define _USE_MATH_DEFINES // For M_PI
#include <math.h>
#include <assert.h>
#include <complex.h>

#include "hann_window.h"
#include "load_raw.h"
#include "mel_weight.h"
#include "input.h"

#define FFT_SIZE  512   // closest value power of 2 above 480 (TS_FRAME)
#define TS_FRAME  480   // 30 ms
#define TS_STRIDE 320   // 20 ms
#define SAMPLES   16000 // 1 s @ 16 kHz
#define FRAMES    49    // Num. of frames of size TS_FRAME in SAMPLES
#define MFCC      10    // Num. of MFCCs per frame

struct complex_float_t {
	float real;
	float img;
};

void usage(char *cmd)
{
    fprintf(stderr, "Usage: %s <.wav or .raw FILE>\n", cmd);
    exit(1);
}

float get_max(float* a, int length)
{
    int i;
    float max = a[0];
    for (i = 1; i < length; i++) {
        if (a[i] > max) {
            max = a[i];
	}
    }

    return max;
}

int frame_spectrogram(float* ts /* time series */, int (*spec) /* spectrogram 1x10 */)
{
    size_t fft_scratch_size = 0;

    // Last FFT_SIZE - TS_FRAME values are kept zeroed (padded)
    float input[FFT_SIZE] = { 0 };
    for (int i = 0; i <  TS_FRAME; i++) {
        input[i] = ts[i];
    }

    struct complex_float_t* output;
    output = malloc((FFT_SIZE / 2 + 1) * sizeof(struct complex_float_t));
    if (output == NULL) {
        printf("malloc() failed!\n");
        exit(1);
    }

    // Apply Hann window to avoid abrupt cuts on frame edges.
    apply_hann_window(input);

    kiss_fftr_cfg kfft_cfg = kiss_fftr_alloc(FFT_SIZE, 0, NULL, &fft_scratch_size);
    if (kfft_cfg != NULL) {
        printf("FFT sizing failed!\n");
    } else {
        printf("FFT scratch size needed = %ld KiB\n", fft_scratch_size/1024);
    }

    void* fft_scratch = malloc(fft_scratch_size);
    if (fft_scratch == NULL) {
        printf("malloc() failed!\n");
	exit(1);
    }

    kfft_cfg = kiss_fftr_alloc(FFT_SIZE, 0, fft_scratch, &fft_scratch_size);
    if (kfft_cfg != fft_scratch) {
        printf("FFT size allocation failed!\n");
    }

    // FFT
    kiss_fftr((kiss_fftr_cfg)kfft_cfg, input, (kiss_fft_cpx*)output);
    // add check
    free(fft_scratch);

    float spectrum_bins[257];
    for (int i = 0; i < (FFT_SIZE / 2 + 1); i++) {
        struct complex_float_t c;
        // Print magnitudes of the spectrum bins.
        c = output[i];
        spectrum_bins[i] = sqrtf((c.real * c.real) + (c.img * c.img));
        printf("i: %d\t, %.25f\n", i, spectrum_bins[i]);
        // printf("i: %d, %f + %fj\n", i, c.real, c.img);
    }

    // 40 mel bins returned in the first 40 elements of spectrum_bins (reused).
    apply_mel_weight(spectrum_bins);

    // Upper half zeroed as 2N Makhoul is used for padding.
    float mel_bins[2 * 40] = { 0 };
    for (int i = 0; i < 40; i++) {
       // Adding 1e-6 before log() computes the stabilized log, but I'm not
       // totally convinced that's necessary here. I´ll leave this addition by
       // now so the numbers match the Python reference numbers.
       mel_bins[i] = logf(spectrum_bins[i] + (float) 1/1000000);
    }
    for (int i = 0; i < 40; i++) printf("%.25f,\n", mel_bins[i]);

    // DCT-II. Using complex.h, but cexp can be implemented using sin and cos,
    // i.e. using Euler's formula. No sure how 'complex' type will be handled
    // in the embedded system tho.
    // TODO(gromero): check returns below
    kfft_cfg = kiss_fftr_alloc(80, 0, NULL, &fft_scratch_size);
    fft_scratch = malloc(fft_scratch_size);
    kfft_cfg = kiss_fftr_alloc(80, 0, fft_scratch, &fft_scratch_size);
    assert(kfft_cfg == fft_scratch);
    kiss_fftr((kiss_fftr_cfg)kfft_cfg, mel_bins, (kiss_fft_cpx*)output);
    free(fft_scratch);

    // For the final spectrogram, only the first 10 DCT values will be taken to
    // form the MFCCs (mel-log filterbank cepstral coeficients).
    float dct[40]; // Only 10 first cepstrum coeficients will be used
    for (int i = 0; i < 40; i++) {
	float complex z = output[i].real + output[i].img * I;
	dct[i] = creal(z * 2.0 * cexp(-I * M_PI * i * 0.5 / 40));
    }
    free(output);
    for (int i = 0; i < 40; i++) printf("dct[%d] = %.25f\n", i, dct[i]);

    float mfcc[40];
    for (int i = 0; i < 40; i++) {
	// I think Tensorflow's mfccs_from_log_mel_spectrograms() is screwed up,
	// but will keep this math for comparison purposes for now and mainly
	// because the model ended up trained with that TF math.
	// TODO(gromero): check with Everton if that math really sucks in TF.
	mfcc[i] = dct[i] * (1.0 / sqrtf(40 /* num. mel bins */ * 2));
    }
    for (int i = 0; i < 10; i++) printf("mfcc[%d] = %2f\n", i, mfcc[i]);

    // scale and zero point taken from trained model
    float input_scale = 0.5847029089927673;
    float input_zero_point = 83;
    //int spec[10]; // We've got 40 MFCCs, but we only use 10 for the spectrogram
    for (int i = 0; i < 10; i++) {
        spec[i] = (int8_t)(mfcc[i] / input_scale + input_zero_point);
    }
    for (int i = 0; i < 10; i++) printf("spectrogram[%d] = %2d\n", i, spec[i]);
}

int spectrogram(float* ts /* time series */, int (*s)[10] /* spectrogram tensor 49x10 */)
{
    // Normalize
    float max = get_max(ts, SAMPLES);
    printf("Normalization, max = %.25f\n", max);
    for (int i = 0; i < SAMPLES; i++) {
        ts[i] /= max;
    }

    // Compute spectrogram for each of the FRAMES frames
    for (int i = 0; i < FRAMES; i++) {
        int frame_start = TS_STRIDE * i;
        frame_spectrogram(&ts[frame_start], s[i]);
    }
}

int main(int argc, char* argv[])
{
    float pcm_samples[SAMPLES];
    int spectrogram_tensor[FRAMES][MFCC];

    if (argc != 2) {
        usage(argv[0]);
    }

    // Load raw 24-bit, signed, little endian, PCM
    load_raw_from_buffer(input, SAMPLES, pcm_samples);

    // Generate spectrogram tensor (49x10) over 1 s (16000 samples @ 16 kHz)
    // TODO(gromero): add checks
    spectrogram(pcm_samples, spectrogram_tensor);

    // Print output tensor (will be removed)
    printf("spectrogram_tensor[%d][%d] = {\n", FRAMES, MFCC);
    for (int i = 0; i < FRAMES; i++) {
	printf("{ ");
        for (int j = 0; j < MFCC; j++) {
            printf("%4d", spectrogram_tensor[i][j]);
	    if ((j + 1) % MFCC) {
                printf(", ");
	    }
	}
	printf(" },\n");
    }
    printf("};\n");
}
