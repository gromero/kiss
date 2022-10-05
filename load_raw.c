#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <inttypes.h>
#include <unistd.h>
#include <assert.h>

int load_raw(char* path, int sample_offset, int samples, float* output)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open(): failed to open input file");
	exit(1);
    }

    if (sample_offset != 0) {
        // assert(offset < file_size - 3);
        int offset = sample_offset * 3; /* 24 bits per sample, i.e. PCM 24-bit */
	lseek(fd, offset, SEEK_CUR);
    }

    // TODO(gromero): add assert for loading 16000 samples from file, exactly
    int ins = 16000;
    if (samples < ins)
        ins = samples;

    uint8_t a, b, c;
    float f; // TODO(gromero): remove me, just debug
    printf("ts = [ ");
    for (int j = 0; j < ins; j++) {
	// raw 24-bit PCM, little-endian, signed
	// TODO(gromero): refactor this mess
        if (read(fd, &c, 1) != 1) return j+1;
        if (read(fd, &b, 1) != 1) return j+1;
	if (read(fd, &a, 1) != 1) return j+1;
	uint32_t i = (uint32_t) a << 24 | b << 16 | c << 8;
        f = output[j] = ((float) i) * (1.0 / ((float) 0x80000000));

        printf("%#.25f,\n", f);
    }
    printf("]\n");
}
