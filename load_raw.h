#ifndef _LOAD_RAW_H
#define _LOAD_RAW_H

#include <inttypes.h>

int load_raw(char* path, int sample_offset, int samples, float* output);

int load_raw_from_buffer(uint8_t* buffer, int samples, float* output);

#endif
