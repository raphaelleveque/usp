objects = primos.o main.o
# Foi criada uma variável objects

# $(objects) acesso a variável
all : $(objects)
	gcc -o executavel $(objects)

run:
	./executavel

zip:
	zip exercicio02 main.c primos.h primos.c Makefile

primos.o: primos.h
main.o: primos.h

clean: 
	rm *.o executavel