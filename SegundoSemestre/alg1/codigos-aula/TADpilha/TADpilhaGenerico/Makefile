objects = pilha.o main.o
# Foi criada uma variável objects

# $(objects) acesso a variável
teste : $(objects)
	gcc -o teste $(objects)

pilha.o: pilha.h
main.o: pilha.h

clean: 
	rm *.o teste