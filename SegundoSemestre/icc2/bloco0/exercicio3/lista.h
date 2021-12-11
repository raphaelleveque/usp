#ifndef LISTA_H_
#define LISTA_H_
//#include "strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//

typedef char* string_t;
typedef struct alfabeto alfabeto_t;

//



typedef string_t elem;
typedef struct no no_t;
typedef struct lista lista_t;

struct no {
    elem info;
    no_t *prox, *anterior;
};

struct lista {
    no_t *inicio, *fim;
    int tam;
};

//
struct alfabeto {
    no_t *no;
};

//



lista_t *cria();
void liberar(lista_t *l);
int insere(lista_t *l, elem palavra);
#endif