objetos = main.o conchas.o

all: $(objetos)
	gcc -o exe $(objetos)

run:
	./exe

zip:
	zip ordenacao-acochegante main.c conchas.h conchas.c Makefile

conchas.o: conchas.h
main.o: conchas.h

clean:
	rm *.o