// ARVORE.C 
#include "arvore.h"

arvore_t *cria() {
    arvore_t *a = malloc(sizeof(arvore_t));
    a->raiz = NULL;
    return a;
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


no_t *busca_pai(no_t *raiz, int id) {
    if (raiz == NULL)
        return NULL;
    
    if (raiz != NULL && raiz->idEsq == id)
        return raiz;
    if (raiz != NULL && raiz->idDir == id)
        return raiz;
    
    no_t *p = busca_pai(raiz->esq, id);  
    if (p == NULL)
        p = busca_pai(raiz->dir, id);  
        
    return p;
}


// Se pai == -1, então inserir na raiz 
// Caso contrário, insere no lado esquerdo de pai
int inserir_esq(arvore_t *a, no_t tmp, no_t *pai) {
    no_t *p = malloc(sizeof(no_t));
    *p = tmp;
    p->esq = NULL;
    p->dir = NULL;
    
    if (pai == NULL) {
        // Se a raiz da árvore for NULL, então a árvore está vazia 
        if (a->raiz == NULL) {
            a->raiz = p;
        } else {
            free(p);
            return 0;
        }
    } else {
        // Encontrei o pai, e seu filho esquerdo está disponível para inserir
        if (pai != NULL && pai->esq == NULL) {
            pai->esq = p;
        } else {
            free(p);
            return 0;
        }
    }
    return 1;
}



int inserir_dir(arvore_t *a, no_t tmp, no_t *pai) {
    no_t *p = malloc(sizeof(no_t));
    *p = tmp;
    p->esq = NULL;
    p->dir = NULL;
    
    if (pai == NULL) {
        if (a->raiz == NULL) {
            a->raiz = p;
        } else {
            free(p);
            return 0;
        }
    } else {
        if (pai != NULL && pai->dir == NULL) {
            pai->dir = p;
        } else {
            free(p);
            return 0;
        }
    }
    return 1;
}

int soma(no_t *raiz) {
    if (raiz != NULL) {
        int sum = 0;
        int a, b;
        a = soma(raiz->esq);
        b = soma(raiz->dir);
        sum = a + b;
        if (a == -1 || b == -1)
            return -1;
        if (sum == raiz->info)
            return raiz->info;
        if (a == 0 && b == 0)
            return raiz->info;
        return -1;
    } else {
        return 0;
    }
}