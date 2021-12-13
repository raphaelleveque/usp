// ARVORE.C 
#include "arvore.h"

arvore_t *criar() {
    arvore_t *a = malloc(sizeof(arvore_t));
    a->raiz = NULL;
    return a;
}


int esta_vazia(arvore_t *a) {
    assert(a != NULL);
    if (a->raiz == NULL) 
        return 1;
    return 0;
}

// Consiste em ter que chegar até uma folha, e, assim que chegar, removê-la
// Volta para o nó anterior recursivamente
void finalizar(no_t *raiz) {
    if (raiz != NULL) {
        finalizar(raiz->esq);
        finalizar(raiz->dir);
        free(raiz);
    }
}


void pre_ordem(no_t *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->info);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}


void em_ordem(no_t *raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esq);
        printf("%d ", raiz->info);
        em_ordem(raiz->dir);
    }
}


void pos_ordem(no_t *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->info);
    }
}


// É utilizado ponteiro duplo pois o ponteiro da raiz será alterado, e para manter a referência dele, é passado como ponteiro duplo
int inserir(no_t **raiz, elem x) {
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(no_t));
        (*raiz)->info = x;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        return 1;
    }
    
    if ((*raiz)->info == x)
        return 0;
        
    if ((*raiz)->info > x)
        return inserir(&(*raiz)->esq, x);
        
    if ((*raiz)->info < x)
        return inserir(&(*raiz)->dir, x);

}