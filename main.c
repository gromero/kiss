#include <stdio.h>
#include <kissfft/kiss_fftr.h>
#include <math.h>

#include "hann_window.h"
#include "load_raw.h"

#define TS_SIZE 512
#define SAMPLES 16000

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

int main(int argc, char* argv[])
{
    size_t fft_scratch_size = 0;

    float input[TS_SIZE] = { [0 ... (TS_SIZE - 1)] = 1 };  // input

    if (argc != 2) {
        usage(argv[0]);
    }

    load_raw(argv[1], SAMPLES, input);

    exit(10);

    struct complex_float_t* output;
    output = malloc((TS_SIZE / 2 + 1) * sizeof(struct complex_float_t));
    if (output == NULL) {
        printf("malloc() failed!\n");
        exit(1);
    }

    // for (int i = 0; i < W_TS_SIZE; i++) printf("%.25f\n", input[i]);

    apply_hann_window(input);

    kiss_fftr_cfg kfft_cfg =  kiss_fftr_alloc(TS_SIZE, 0, NULL, &fft_scratch_size);
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

    for (int i = 0; i < (TS_SIZE / 2 + 1); i++) {
        struct complex_float_t c;
        c = output[i];
        printf("%f\n", sqrtf(c.real*c.real + c.img*c.img));
    }

    // for (int i = 0; i < W_TS_SIZE; i++) printf("%.25f\n", input[i]);
}
