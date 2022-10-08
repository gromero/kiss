#include <stdio.h>
#include <kissfft/kiss_fftr.h>
#define _USE_MATH_DEFINES // For M_PI
#include <math.h>
#include <assert.h>
#include <complex.h>

#include "hann_window.h"
#include "load_raw.h"
#include "mel_weight.h"

#define TS_SIZE   512
#define FFT_SIZE  512
#define TS_FRAME  480   // 30 ms
#define TS_STRIDE 320   // 20 ms
#define SAMPLES   16000

struct complex_float_t {
	float real;
	float img;
};

// typedef kiss_fft_cpx complex_float_t;

void usage(char *cmd)
{
    fprintf(stderr, "Usage: %s <.wav or .raw FILE>\n", cmd);
    exit(1);
}

void padding(float* t)
{
    int i;

    // Pad with zero FFT_SIZE - TS_FRAME points
    for (i = TS_FRAME; i < FFT_SIZE; i++) {
        t[i] = 0;
    }
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

int main(int argc, char* argv[])
{
    size_t fft_scratch_size = 0;

    // float input[TS_SIZE] = { [0 ... (TS_SIZE - 1)] = 1 };  // input

    float input[SAMPLES];

    if (argc != 2) {
        usage(argv[0]);
    }

    int amount_of_samples_to_load = TS_FRAME;
    load_raw(argv[1], 2 * TS_STRIDE, amount_of_samples_to_load, input);

    struct complex_float_t* output;
    output = malloc((TS_SIZE / 2 + 1) * sizeof(struct complex_float_t));
    if (output == NULL) {
        printf("malloc() failed!\n");
        exit(1);
    }

    // for (int i = 0; i < W_TS_SIZE; i++) printf("%.25f\n", input[i]);

    // Normalize.
    // float max = get_max(input, amount_of_samples_to_load);
    // 'max' must be the max value considering the whole time series (1s,
    // hence for testing purposes, just hard code it for now.
    float max = 0.025794744;
    printf("normalization, max = %.25f\n", max);
    for (int i = 0; i < amount_of_samples_to_load; i++) {
        input[i] /= max;
    }

    // Apply Hann window to avoid abrupt cuts on frame edges.
    apply_hann_window(input);

    // Pad 480 frame to 512 (next power of 2 value close to 480) before applying
    // FFT.
    padding(input);

    kiss_fftr_cfg kfft_cfg = kiss_fftr_alloc(TS_SIZE, 0, NULL, &fft_scratch_size);
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

    kfft_cfg = kiss_fftr_alloc(TS_SIZE, 0, fft_scratch, &fft_scratch_size);
    if (kfft_cfg != fft_scratch) {
        printf("FFT size allocation failed!\n");
    }

    // FFT
    kiss_fftr((kiss_fftr_cfg)kfft_cfg, input, (kiss_fft_cpx*)output);

    float spectrum_bins[257];
    for (int i = 0; i < (TS_SIZE / 2 + 1); i++) {
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
    for (int i; i < 40; i++) {
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
    free(fft_scratch);
    kfft_cfg = kiss_fftr_alloc(80, 0, NULL, &fft_scratch_size);
    fft_scratch = malloc(fft_scratch_size);
    kfft_cfg = kiss_fftr_alloc(80, 0, fft_scratch, &fft_scratch_size);
    assert(kfft_cfg == fft_scratch);
    kiss_fftr((kiss_fftr_cfg)kfft_cfg, mel_bins, (kiss_fft_cpx*)output);

    // For the final spectrogram, only the first 10 DCT values will be taken to
    // form the MFCCs (mel-log filterbank cepstral coeficients).
    float dct[40]; // Only 10 first cepstrum coeficients will be used
    for (int i; i < 40; i++) {
	float complex z = output[i].real + output[i].img * I;
	dct[i] = creal(z * 2.0 * cexp(-I * M_PI * i * 0.5 / 40));
    }
    for (int i = 0; i < 40; i++) printf("dct[%d] = %.25f\n", i, dct[i]);
}
