sources = hann_window.c load_raw.c mel_weight.c main.c
headers = hann_window.h load_raw.h mel_weight.h

main:	$(sources) $(headers)
	gcc -O0 -g hann_window.c load_raw.c mel_weight.c main.c -o main -I./include -L./lib -lkissfft-float -lm

run:	main
	LD_LIBRARY_PATH=./lib ./main $(FILE)

clean:
	rm -fr *.o
	rm -fr main
