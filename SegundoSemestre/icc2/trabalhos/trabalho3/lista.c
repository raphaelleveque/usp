#include "lista.h"

lista_t *criar() {
    lista_t *l = malloc(sizeof(lista_t));
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

int inserir(lista_t *l, dados_t temporario) {
    assert(l != NULL);

    dados_t *p = malloc(sizeof(dados_t));
    *p = temporario;
    p->anterior = NULL;
    p->prox = NULL;

    dados_t *aux, *ant;
    ant = NULL;
    aux = l->inicio;
    while (aux != NULL && temporario.tempoInicial > aux->tempoInicial) {
        ant = aux;
        aux = aux->prox;
    }

    // Se o elemento já tiver inserido na lista
    if (aux != NULL && temporario.tempoInicial == aux->tempoInicial) {
        while (aux != NULL && temporario.prioridade < aux->prioridade) {
            ant = aux;
            aux = aux->prox;
        }
    }


    if (ant == NULL) {
        p->prox = l->inicio;
        if (l->inicio != NULL)
            l->inicio->anterior = p;
        else
            l->fim = p;
        l->inicio = p;

    } else { 
        p->prox = ant->prox;
        ant->prox = p;
        if (p->prox != NULL)
            p->prox->anterior = p;
        else
            l->fim = p;
        p->anterior = ant;
    }
    return 1;
}


void imprimir(lista_t *l) {
    assert(l != NULL);
    
    dados_t *p = l->inicio;
    while (p != NULL) {
        printf("%d %d %d %d\n", p->codigo, p->tempoInicial, p->volume, p->prioridade);
        p = p->prox;
    }
    printf("\n");
}