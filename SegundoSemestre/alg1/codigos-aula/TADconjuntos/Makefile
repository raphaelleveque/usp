objects = conjuntos.o main.o

conjuntos : $(objects)
	gcc -o conjuntos $(objects)

conjuntos.o: conjuntos.h
main.o: conjuntos.h

clean : 
	rm *.o conjuntos
