objects = strings.o main.o
# Foi criada uma variável objects

# $(objects) acesso a variável
all: $(objects)
	gcc -o executavel $(objects)

run:
	./executavel

zip:
	zip exercicio03 main.c strings.h strings.c Makefile

strings.o: strings.h
main.o: strings.h

clean: 
	rm *.o executavel