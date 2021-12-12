// ARVORE.H 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int elem;
typedef struct no no_t;
typedef struct arvore arvore_t;

struct no {
    no_t *esq, *dir;
    elem info;
    int id, idEsq, idDir;
};

struct arvore {
    no_t *raiz;
};


arvore_t *cria();
void finalizar(no_t *raiz);
no_t *busca_pai(no_t *raiz, int id);
int inserir_esq(arvore_t *a, no_t tmp, no_t *pai);
int inserir_dir(arvore_t *a, no_t tmp, no_t *pai);
int soma(no_t *raiz);