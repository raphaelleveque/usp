#include "treap.h"

// Função para rotacionar para a direita
treapNode_t *rightRotate(treapNode_t *y) {
    treapNode_t *x = y->esq, *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    return x;
}

treapNode_t *leftRotate(treapNode_t *x) {
    treapNode_t *y = x->dir, *T2 = y->esq;

    // Perform rotation
    y->esq = x;
    x->dir = T2;

    // Return new raiz
    return y;
}

// Função para liberar a memória
void finalizar(treapNode_t *raiz) {
    if (raiz != NULL) {
        finalizar(raiz->esq);
        finalizar(raiz->dir);
        free(raiz);
    }
}

// Função para adicionar uma nova chave
treapNode_t *newNode(int chave, int prioridade) {
    treapNode_t *temp = malloc(sizeof(treapNode_t));
    temp->chave = chave;
    temp->prioridade = prioridade;
    temp->esq = temp->dir = NULL;
    return temp;
}

// Procura uma chave na árvore
treapNode_t *search(treapNode_t *raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) return raiz;

    if (raiz->chave < chave) return search(raiz->dir, chave);

    return search(raiz->esq, chave);
}

// Função recursiva para inserir um nó
treapNode_t *insert(treapNode_t *raiz, int chave, int prioridade) {
    // Se a raiz for NULL, crie um nó
    if (!raiz) return newNode(chave, prioridade);

    // Se a chave for menor que a raiz
    if (chave <= raiz->chave) {
        // Insere na subárvore esquerda
        raiz->esq = insert(raiz->esq, chave, prioridade);

        if (raiz->esq->prioridade > raiz->prioridade) raiz = rightRotate(raiz);
    } else  // Se a chave for maior
    {
        // Insere na subárvore direita
        raiz->dir = insert(raiz->dir, chave, prioridade);

        if (raiz->dir->prioridade > raiz->prioridade) raiz = leftRotate(raiz);
    }
    return raiz;
}

// Função recursiva para deletar um nó da árvore
treapNode_t *deleteNode(treapNode_t *raiz, int chave) {
    if (raiz == NULL) return raiz;

    if (chave < raiz->chave)
        raiz->esq = deleteNode(raiz->esq, chave);
    else if (chave > raiz->chave)
        raiz->dir = deleteNode(raiz->dir, chave);

    // Se nó esquerdo for NULL
    else if (raiz->esq == NULL) {
        treapNode_t *temp = raiz->dir;
        free(raiz);
        raiz = temp;  // Filho direito se torna raiz
    }

    // Se nó direito for NULL
    else if (raiz->dir == NULL) {
        treapNode_t *temp = raiz->esq;
        free(raiz);
        raiz = temp;  // Filho esquerdo se torna raiz
    }

    // Se chave está na raiz e tanto esquerdo quanto direito não forem NULL
    else {
        raiz = leftRotate(raiz);
        raiz->esq = deleteNode(raiz->esq, chave);
    }

    return raiz;
}

// Função para printar a árvore em pré-ordem
void pre_ordem(treapNode_t *raiz) {
    if (raiz != NULL) {
        printf("(%d, %d) ", raiz->chave, raiz->prioridade);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

// Função para printar a árvore em em-ordem
void em_ordem(treapNode_t *raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esq);
        printf("(%d, %d) ", raiz->chave, raiz->prioridade);
        em_ordem(raiz->dir);
    }
}

// Função para printar a árvore em pós-ordem
void pos_ordem(treapNode_t *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("(%d, %d) ", raiz->chave, raiz->prioridade);
    }
}


// Todas as funções abaixo servem para printar a árvore em largura

void printLevelOrder(treapNode_t *raiz) {
    int h = height(raiz);
    int i;
    for (i = 1; i <= h; i++) printCurrentLevel(raiz, i);
}

// Imprime os nós no nível atual
void printCurrentLevel(treapNode_t *raiz, int level) {
    if (raiz == NULL) return;
    if (level == 1)
        printf("(%d, %d) ", raiz->chave, raiz->prioridade);
    else if (level > 1) {
        printCurrentLevel(raiz->esq, level - 1);
        printCurrentLevel(raiz->dir, level - 1);
    }
}

// Função que retorna a altura do nó atual
int height(treapNode_t *node) {
    if (node == NULL)
        return 0;
    else {
        // Calcula recursivamente a altura de cada subárvore
        int lheight = height(node->esq);
        int rheight = height(node->dir);

        // Escolhe a maior delas
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
