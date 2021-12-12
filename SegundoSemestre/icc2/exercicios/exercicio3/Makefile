all:
	gcc *.c -o exe -g -Wall -Werror
run:
	./exe 
zip:
	zip ex03 main.c lista.h lista.c Makefile
val:
	valgrind ./exe <casos/2.in --leak-check=full --track-origins=yes