#include "pilha.h"

struct pilha{
    elem *topo;
    elem *pilha;
    int tam;
};

pilha_t *pop(pilha_t *p, elem *c);

pilha_t *create(){
    pilha_t *p = malloc(sizeof (pilha_t));
    p->topo = NULL;
    p->pilha = NULL;
    p->tam = 0;

    return p;
}

pilha_t *push(pilha_t *p, elem *c){
    p->tam++;
    p->pilha = realloc(p->pilha, (p->tam) * sizeof (pilha_t));
    p->pilha[p->tam - 1] = *c;
    if (p->tam == 1) return p;
    p = pop(p, c);
    return p;
}

pilha_t *pop(pilha_t *p, elem *c){
    elem anterior = p->pilha[p->tam - 2];
    switch (*c) {
        case ']':
            if (anterior == '[') {
                p->tam -= 2;
                p->pilha = realloc(p->pilha, (p->tam) * sizeof(pilha_t));
            }
            else{
                scanf("%*[^\n]");
            }
            break;

        case ')':
            if (anterior == '(') {
                p->tam -= 2;
                p->pilha = realloc(p->pilha, (p->tam) * sizeof(pilha_t));
            }
            else{
                scanf("%*[^\n]");
            }
            break;

        case '}':
            if (anterior == '{') {
                p->tam -= 2;
                p->pilha = realloc(p->pilha, (p->tam) * sizeof(pilha_t));
            }
            else{
                scanf("%*[^\n]");
            }
            break;

        case '"':
            if (anterior == '"') {
                p->tam -= 2;
                p->pilha = realloc(p->pilha, (p->tam) * sizeof(pilha_t));
            }
            break;
    }
    if (p->tam == 0){
        p->pilha = NULL;
    }
    return p;
}

void printandoBalanceado(pilha_t *p){
    if (p->tam == 0)
        printf("BALANCEADO\n");
    else
        printf("NÃO BALANCEADO\n");
}