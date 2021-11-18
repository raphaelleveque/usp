#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no node;
typedef short elem;
struct no {
    elem info;
    node *prox;
    node *anterior;
};

typedef struct lista {
    node *ini, *fim;
    int tam;
} lista_t;

lista_t *cria();
void liberar(lista_t *l);
void insere(lista_t *l, elem x);
void preSoma(lista_t *num1, lista_t *num2);
void imprimeLista(lista_t *l);
void preDiferenca(lista_t *num1, lista_t *num2);
int maiorOuMenor(lista_t *num1, lista_t *num2);
void soma(lista_t *num1, lista_t *num2);
void diferenca(lista_t *num1, lista_t *num2, int sinal);
