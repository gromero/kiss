#include "hann_window.h"

/*
 * Apply a Hann window to a time series.
 * Time series size is fixed at W_TS_SIZE.
 */
void apply_hann_window(float* ts)
{
    int i;

    for (i = 0; i < W_TS_SIZE; i++) {
        ts[i] = ts[i] * hann_window[i];
    }
}
