#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int elem ;
typedef struct lista lista_t;
typedef struct no node;

lista_t *cria();
void liberar(lista_t *l);
void insere(lista_t *l, elem x);
void imprimir(lista_t *l);
void rotaciona(lista_t *l, int nRotacoes);