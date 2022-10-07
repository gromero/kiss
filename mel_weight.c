#include <stdio.h>
#include "mel_weight.h"

// dot product [1, 257] x [257, 40] (mel weight)
// That's pretty much a dot product of matrices.
void apply_mel_weight(float *s /* spectrum bins = 257 */)
{
    int i, j;
    float a;
    float r[40];

    for (i = 0; i < 40; i++) {
        a = 0;
        for (j = 0; j < 257; j++) {
            a += s[j] * mel_weight[j][i];
        }

        r[i] = a;
    }

    // Reuse first 40 elements in 's' to hold mel bins.
    // TODO(gromero): refactor this mess.
    for (int i = 0; i < 40; i++) {
        s[i] = r[i];
        printf(" - %.25f\n", s[i]);
    }
}
