objetos = main.o fila.o

all: $(objetos)
	gcc -o exe $(objetos)

run:
	./exe

zip:
	zip exercicio04 main.c fila.h fila.c Makefile

fila.o: fila.h
main.o: fila.h

clean:
	rm *.o exe