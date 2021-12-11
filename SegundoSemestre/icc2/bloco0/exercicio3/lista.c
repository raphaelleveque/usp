#include "lista.h"

lista_t *cria() {
    lista_t *l = malloc(sizeof(lista_t));
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
    return l;
}

void liberar(lista_t *l) {
    assert(l != NULL);

    no_t *p = l->inicio;
    while (p != NULL) {
        l->inicio = p->prox;
        free(p->info);
        free(p);
        p = l->inicio;
    }
    free(l);
}

int insere(lista_t *l, elem palavra) {
    assert(l != NULL);

    no_t *p = malloc(sizeof(no_t));
    p->info = palavra;
    p->prox = NULL;
    p->anterior = NULL;

    no_t *ant, *aux;
    ant = NULL;
    aux = l->inicio;
    // No fim do while, o aux sera maior que palavra[0]
    while (aux != NULL && aux->info[0] < palavra[0]) {
        ant = aux;
        aux = aux->prox;
    }

    // Se o elemento já tiver inserido na lista
    if (aux != NULL && strcmp(palavra,aux->info) == 0) {
        free(p->info);
        free(p);
        return 0;
    }

    // Se a lista estiver vazia ou o elemento a ser inserido é o menor da lista
    if (ant == NULL) {
        p->prox = l->inicio;
        // Se a lista já tiver elementos, o antigo primeiro elemento aponta, pela esquerda, para o novo primeiro elemento
        if (l->inicio != NULL) l->inicio->anterior = p;
        else l->fim = p;
        l->inicio = p;
        
    } else {         // Estou inserindo no meio ou no final
        p->prox = ant->prox;
        ant->prox = p;
        if (p->prox != NULL) p->prox->anterior = p;
        else l->fim = p;
        p->anterior = ant;
    }
    l->tam++;
    return 1;
}