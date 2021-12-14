#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreapNode treapNode_t;

struct TreapNode {
    int chave, prioridade;
    treapNode_t *esq, *dir;
};

treapNode_t* rightRotate(treapNode_t* y);
treapNode_t* leftRotate(treapNode_t* x);
treapNode_t* newNode(int chave, int prioridade);
treapNode_t* search(treapNode_t* raiz, int chave);
treapNode_t* insert(treapNode_t* raiz, int chave, int prioridade);
treapNode_t* deleteNode(treapNode_t* raiz, int chave);
void pre_ordem(treapNode_t* raiz);
void em_ordem(treapNode_t* raiz);
void pos_ordem(treapNode_t* raiz);
void finalizar(treapNode_t* raiz);
void printLevelOrder(treapNode_t* raiz);
void printCurrentLevel(treapNode_t* raiz, int level);
int height(treapNode_t* node);