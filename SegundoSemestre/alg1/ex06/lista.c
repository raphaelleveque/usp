#include "lista.h"

struct no {
    elem info;
    node *prox;
    node *anterior;
};

struct lista{
    node *ini, *fim;
    int tam;
};



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


void imprimir(lista_t *l){
    node *p = l->ini;
    while(p != NULL){
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}


void rotaciona(lista_t *l, int nRotacoes){
    for (int i = 0; i < nRotacoes; ++i) {
        node *novoPrimeiro = l->fim;
        node *novoUltimo = l->fim->anterior;
        node *antigoPrimeiro = l->ini;

        novoPrimeiro->prox = antigoPrimeiro;
        novoPrimeiro->anterior = NULL;
        novoUltimo->prox = NULL;
        antigoPrimeiro->anterior = novoPrimeiro;

        l->ini = novoPrimeiro;
        l->fim = novoUltimo;
    }
}