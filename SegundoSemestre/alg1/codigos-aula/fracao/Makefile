main: main.o fracao.o
	gcc -o main main.o fracao.o

main.o: main.c fracao.h
	gcc -c main.c

fracao.o: fracao.c fracao.h
	gcc -c fracao.c

clean:
	rm *.o main