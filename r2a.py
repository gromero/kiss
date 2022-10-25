#!/bin/python3

#
# Hasty script to onvert from .raw audio file to C array.
# Usage: ./r2a.py <pcm24.raw>

import sys

LINE_BREAK = 12

fd = open(sys.argv[1], "rb")

print("uint8_t input[] = {")
print("\t", end="")

i = 1
d = fd.read(1)
while len(d) == 1:
    print("0x" + d.hex() + ", ", end="")
    d = fd.read(1)
    if (i % LINE_BREAK) == 0:
        print("") # break line
        print("\t", end="")
    i = i + 1

print("\n};")
