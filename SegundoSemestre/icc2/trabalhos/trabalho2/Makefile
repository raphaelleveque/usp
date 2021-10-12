var = main.o audio.o

all: $(var)
	gcc -o exe $(var) -lm

run:
	./exe

zip:
	zip trabalho2 main.c audio.h audio.c Makefile

audio.o: audio.h
main.o: audio.h

clean:
	rm *.o