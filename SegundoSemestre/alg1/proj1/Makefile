FLAGS = -g -lm -Wall -Werror
VFLAGS = --show-leak-kinds=all --track-origins=yes --leak-check=full --tool=memcheck --show-reachable=yes -s

all:
	gcc -o exe *.c $(FLAGS) 

val: all
	valgrind $(VFLAGS) ./exe 

run:
	./exe

zip:
	zip projeto1 main.c skiplist.c skiplist.h Makefile

clean:
	rm *.o