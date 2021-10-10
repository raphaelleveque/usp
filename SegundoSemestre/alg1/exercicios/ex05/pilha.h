#include <stdio.h>
#include <stdlib.h>

typedef char elem;
typedef struct pilha pilha_t;

pilha_t *create();
pilha_t *push(pilha_t *p, elem *x);
void printandoBalanceado(pilha_t *p);