objetos = main.o frequentes.o

all: $(objetos)
	gcc -o exe $(objetos) -Wall -Werror -g

run:
	./exe

zip:
	zip exercicio01 main.c frequentes.h frequentes.c Makefile

frequentes.o: frequentes.h
main.o: frequentes.h

clean:
	rm *.o