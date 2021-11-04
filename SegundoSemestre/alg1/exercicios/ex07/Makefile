objetos = main.o lista.o

all: $(objetos)
	gcc -o exe $(objetos)

run:
	./exe

zip:
	zip exercicio07 main.c lista.h lista.c Makefile

lista.o: lista.h
main.o: lista.h

clean:
	rm *.o
