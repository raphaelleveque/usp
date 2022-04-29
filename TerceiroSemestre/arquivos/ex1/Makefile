all:
	gcc *.c -o exe -Wall -Wextra
debug:
	gcc *.c -o exe -Wall -Wextra -pedantic -Werror=implicit-function-declaration -fsanitize=address

run:
	./exe

zip:
	zip Ex1 main.c funcoesAuxiliares.c funcoesAuxiliares.h comandos.c comandos.h Makefile