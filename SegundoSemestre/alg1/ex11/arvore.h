// ARVORE.H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef char* string_t;
typedef int elem;
typedef struct no no_t;
typedef struct arvore arvore_t;

struct no {
    no_t *esq, *dir;
    elem info;
};

struct arvore {
    no_t *raiz;
};

arvore_t *criar();
int esta_vazia(arvore_t *a);
void finalizar(no_t *raiz);
void pre_ordem(no_t *raiz);
void em_ordem(no_t *raiz);
void pos_ordem(no_t *raiz);
int inserir(no_t **raiz, elem x);