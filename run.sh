#!/bin/bash +x

gcc -c hann_window.c -o hann_window.o # Window
gcc -c load_raw.c -o load_raw.o # Load Raw
gcc -c  main.c -o main.o -I./include -L./lib -lkissfft-float # Main
gcc main.o hann_window.o load_raw.o -o main -I./include -L./lib -lkissfft-float -lm # ALL
LD_LIBRARY_PATH=./lib ./main ./yes_from_board_v2.raw # Run

