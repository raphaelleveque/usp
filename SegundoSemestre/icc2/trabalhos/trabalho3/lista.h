#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define TAM 4

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
void escalonamento(lista_t *l);
void liberar(lista_t *l);