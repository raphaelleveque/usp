#include "pilha.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct pilha
{
    int topo;
    elem itens[TamPilha];
};

// Função create da pilha
// Retorna -1 para avisar que a pilha está vazia
pilha_t *create(){
    pilha_t *p = malloc(sizeof(pilha_t));
    assert(p != NULL);   // Assegure que p é diferente de nulo para continuar a execução
                         // Caso contrário, mensagem de erro e execução é interrompida
    
    p->topo = -1;
    return p;
}


void destroy(pilha_t *p)
{
    if (p != NULL)
        free(p);
}


int isEmpty(pilha_t *p)
{
    if (p->topo == -1)
        return 1;
    else
        return 0;
}


int isFull(pilha_t *p)
{
    if (p->topo == TamPilha - 1)
        return 1;
    else
        return 0;
}


int push(pilha_t *p, elem x)
{
    if(isFull(p) == 1)
        return -1;
    
    p->topo++;
    p->itens[p->topo] = x;
    return 1;
}

// elem *x é a posição do topo da pilha
int pop(pilha_t *p, elem *x)
{
    if (isEmpty(p) == 1)
        return -1;
    
    *x = p->itens[p->topo];
    p->topo--;
    return 1;
}


int top(pilha_t *p, elem *x)
{
    if (isEmpty(p) == 1)
        return -1;
    
    *x = p->itens[p->topo];
    return 1;
}