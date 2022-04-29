#ifndef FUNCOESAUXILIARES_H
#define FUNCOESAUXILIARES_H

#include "comandos.h"
#include <stdio.h>
#include <stdlib.h>

void read_line(char* string);
void binary_on_screen(const char *file_name);
void fill_with_dollars(FILE *fp, int len);
void write_in_file(FILE *fp, Person_t *person);
char* read_from_file(FILE *fp, int len, char *string);
void print_person(const Person_t* person);

#endif
