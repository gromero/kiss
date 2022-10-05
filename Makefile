sources = hann_window.c load_raw.c main.c
headers = hann_window.h load_raw.h

main:	$(sources) $(headers)
	gcc hann_window.c load_raw.c main.c -o main -I./include -L./lib -lkissfft-float -lm

run:	main
	LD_LIBRARY_PATH=./lib ./main $(FILE)

clean:
	rm -fr *.o
	rm -fr main
