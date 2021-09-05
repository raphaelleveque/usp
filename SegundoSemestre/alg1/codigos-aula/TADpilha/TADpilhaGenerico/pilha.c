#include "pilha.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct pilha
{
    int topo;
    void **itens;  // VETOR DE VOID*    
    int tamElem;
};

// Função create da pilha
// Retorna -1 para avisar que a pilha está vazia
pilha_t *create(int tamElem){
    pilha_t *p = malloc(sizeof(pilha_t));
    assert(p != NULL);   // Assegure que p é diferente de nulo para continuar a execução
                         // Caso contrário, mensagem de erro e execução é interrompida

    p->itens = (void **)malloc(sizeof(void *) * TamPilha);
    assert(p->itens != NULL);
    
    p->topo = -1;
    p->tamElem = tamElem;
    return p;
}


void destroy(pilha_t *p)
{
    while (p->topo >= 0)
    {
        free(p->itens[p->topo]);
        p->topo--;
    }
    if(p->itens != NULL)
        free(p->itens);
    
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


int push(pilha_t *p, void *x)
{
    if(isFull(p) == 1)
        return -1;
    
    p->topo++;
    p->itens[p->topo] = (void *)malloc(p->tamElem);

    memcpy(p->itens[p->topo], x, p->tamElem);  // Copia o conteúdo de x para dentro de p->itens[p->topo] com o tamanho tamElem
    return 1;
}

// elem *x é a posição do topo da pilha
int pop(pilha_t *p, void *x)
{
    if (isEmpty(p) == 1)
        return -1;
    
    memcpy(x, p->itens[p->topo], p->tamElem);
    free(p->itens[p->topo]);

    p->topo--;
    return 1;
}


int top(pilha_t *p, void *x)
{
    if (isEmpty(p) == 1)
        return -1;
    
    memcpy(x, p->itens[p->topo], p->tamElem);
    p->topo--;
    return 1;
}
