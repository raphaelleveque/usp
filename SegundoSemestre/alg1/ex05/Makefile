obj = main.o pilha.o

all: $(obj)
	gcc -o exe $(obj)

run:
	./exe

zip:
	zip exercicio05 main.c pilha.c pilha.h Makefile

clean:
	rm *.o
