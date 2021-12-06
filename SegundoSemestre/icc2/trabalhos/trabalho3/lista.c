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

    // Primeiro, verifica-se se o código é válido
    while (aux != NULL) {
        if (p->codigo == aux->codigo)
            p->codigo++;
        aux = aux->prox;
    }
    aux = l->inicio;

    // Ordenando pela Prioridade
    while (aux != NULL && temporario.prioridade < aux->prioridade) {
        ant = aux;
        aux = aux->prox;
    }

    // O elemento cujo tempo Inicial é menor vai para o início da fila
    while (aux != NULL && temporario.tempoInicial > aux->tempoInicial && temporario.prioridade == aux->prioridade) {
        ant = aux;
        aux = aux->prox;
    }

    // Se existir algum elemento que possui o mesmo tempo inicial e a mesma prioridade, será ordenado pelo código
    while (aux != NULL && temporario.tempoInicial == aux->tempoInicial && temporario.prioridade == aux->prioridade && temporario.codigo > aux->codigo) {
        ant = aux;
        aux = aux->prox;
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

void escalonamento(lista_t *l) {
    assert(l != NULL);

    int tempo = 1;
    int tam = TAM;
    dados_t *p = l->inicio;
    l->fim->prox = l->inicio;
    l->inicio->anterior = l->fim;

    while (tam > 0) {
        // Se o tempo do clock for menor ou igual ao tempo inicial, então entre no if
        if (p->tempoInicial <= tempo && p->volume > 0) {
            p->volume--;
            tempo++;
            // Se, no início, tiver um processo com uma prioridade maior, o processo voltará para o início da lista
            if (l->inicio->tempoInicial == tempo) {
                p = l->inicio;
                continue;
            }
            if (p->volume == 0) {
                printf("%d %d\n", p->codigo, tempo - 1);
                tam--;
            }
        }
        // Agora é a vez do próximo da fila de prioridade
        p = p->prox;
    }
}

void liberar(lista_t *l) {
    dados_t *aux = l->inicio;
    l->inicio->anterior = NULL;
    l->fim->prox = NULL;
    while(aux != NULL){
        l->inicio = l->inicio->prox;
        free(aux);
        aux = l->inicio;
    }
    free(l);
    return;
}