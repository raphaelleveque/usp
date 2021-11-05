#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int elem;

typedef struct no node;
struct no {
    elem info;
    node *prox;
    node *anterior;
};

typedef struct lista {
    node *ini, *fim;
    int tam;
} lista_t;

lista_t *cria();
void liberar(lista_t *l);
void insere(lista_t *l, elem x);
