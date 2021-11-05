#include "lista.h"

lista_t *cria(){
    lista_t *l;
    l = malloc(sizeof(lista_t));
    assert(l != NULL);
    l->ini = NULL;
    l->fim = NULL;
    l->tam = 0;

    return l;
}


void liberar(lista_t *l){
    if(l != NULL){
        node *p = l->ini;
        while(p != NULL){
            l->ini = p->prox;
            free(p);
            p = l->ini;
        }
        free(l);
    }
}


void insere(lista_t *l, elem x){
    assert(l != NULL);

    node *p = malloc(sizeof(node));
    p->info = x;
    p->prox = NULL;
    p->anterior = l->fim;
// if lista vazia
    if(l->ini == NULL){
        l->ini = p;
    }
    else{
        l->fim->prox = p;
    }
    l->fim = p;
    l->tam++;
}

