#include <stdio.h>
#include <stdlib.h>

typedef char* string_t;

typedef struct conchas{
    double raio;
    string_t nome;
} conchas_t;

string_t lendoString();
void sort(conchas_t *conchas, long nConchas);