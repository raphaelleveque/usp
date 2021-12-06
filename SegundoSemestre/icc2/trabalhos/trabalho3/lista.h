#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int elem;
typedef struct dados dados_t;

typedef struct dados {
    int codigo;
    int tempoInicial;
    int volume;
    int prioridade;
    dados_t *prox, *anterior;
} dados_t;

typedef struct lista {
    dados_t *inicio, *fim;
} lista_t;


lista_t *criar();
int inserir(lista_t *l, dados_t temporario);
void imprimir(lista_t *l);
