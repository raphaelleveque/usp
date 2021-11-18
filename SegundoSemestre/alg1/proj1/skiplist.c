// Skiplist.c
#include "skiplist.h"

Skiplist *cria(int nivelMAX, double p) {
    Skiplist *sk = malloc(sizeof(Skiplist));
    if (sk != NULL) {
        sk->nivelMAX = nivelMAX;
        sk->p = p;
        sk->nivel = 0;
        sk->inicio = novoNo("", nivelMAX, "");
    }
    return sk;
}

node *novoNo(string chave, int nivel, string definicao) {
    node *novo = malloc(sizeof(node));
    novo->chave = malloc(55 * sizeof(char));
    novo->definicao = malloc(145 * sizeof(char));
    if (novo != NULL) {
        strcpy(novo->chave, chave);
        strcpy(novo->definicao, definicao);
        novo->prox = malloc((nivel + 1) * sizeof(node)); // Nível + 1 = todos os níveis + nível 0
        for (int i = 0; i < nivel + 1; i++) {
            novo->prox[i] = NULL;
        }
    }
    return novo;
}

void liberaSkiplist(Skiplist *sk) {
    if (sk == NULL)
        return;

    node *no, *atual;
    atual = sk->inicio->prox[0];
    while (atual != NULL) {
        no = atual;
        atual = atual->prox[0];
        free(no->chave);
        free(no->definicao);
        free(no->prox);
        free(no);
    }
    free(sk->inicio->prox);
    free(sk->inicio->chave);
    free(sk->inicio->definicao);
    free(sk->inicio);
    free(sk);
}

node *buscaSkipList(Skiplist *sk, string chave) {
    if (sk == NULL)
        return NULL;

    node *atual = sk->inicio;
    // Partindo do maior nível, vá para o próximo nó
    // enquanto a chave for maior do que o próximo nó
    // Senão, desça de nível e continue a buscaSkipList

    for (int i = sk->nivel; i >= 0; i--) {
        while (atual->prox[i] != NULL && strcmp(atual->prox[i]->chave, chave) < 0) {
            atual = atual->prox[i];
        }
    }
    // Acesse o nível 0 do próximo nó, que é onde a chave deve estar (se existir)
    atual = atual->prox[0];
    if (atual != NULL && strcmp(atual->chave, chave) == 0)
        return atual;
    else
        return NULL;
}

int insereSkipList(Skiplist *sk, string chave, string definicao) {
    if (sk == NULL)
        return 0;

    node *atual = sk->inicio;
    node **aux;
    aux = malloc((sk->nivelMAX + 1) * sizeof(node *));
    for (int i = 0; i <= sk->nivelMAX; i++)
        aux[i] = NULL;

    // Partindo do maior nível, vá para o próximo nó enquanto a chave for maior do que a do próximo nó
    // Caso contrário, insira o nó no array auxiliar, desça um nível e continue a busca
    for (int i = sk->nivel; i >= 0; i--) {
        while (atual->prox[i] != NULL && strcmp(atual->prox[i]->chave, chave) < 0) {
            atual = atual->prox[i];
        }
        aux[i] = atual;
    }
    // Acessa o nível 0 do próximo nó, que é onde a chave deve ser encontrada
    atual = atual->prox[0];

    // Cria e insere um novo nó se a chave não existir
    // Se ele tiver no final da lista (atual == NULL), ou se a chave do nó atual não for igual a chave a ser inserida, será criado um novo nó
    if (atual == NULL || strcmp(atual->chave, chave) != 0) {
        // Sorteia o nível
        int novoNivel = sorteiaNivel(sk);
        node *novo = novoNo(chave, novoNivel, definicao);
        if (novo == NULL) {
            free(aux);
            return 0;
        }

        // Se o nível sorteado for maior que o nível atual da skiplist, atualizar os novos níveis do array auxiliar
        if (novoNivel > sk->nivel) {
            for (int i = sk->nivel + 1; i <= novoNivel; i++)
                aux[i] = sk->inicio;
            sk->nivel = novoNivel;
        }

        for (int i = 0; i <= novoNivel; i++) {
            novo->prox[i] = aux[i]->prox[i];
            aux[i]->prox[i] = novo;
        }
        free(aux);
        return 1;
    }
    free(aux);
    return 0;
}

int sorteiaNivel(Skiplist *sk) {
    // Sorteia o nível para o nó
    double r = (double)rand() / RAND_MAX;
    int nivel = 0;
    while (r < sk->p && nivel < sk->nivelMAX) {
        nivel++;
        r = (double)rand() / RAND_MAX;
    }
    return nivel;
}

int removeSkiplist(Skiplist *sk, string chave) {
    if (sk == NULL)
        return 0;

    node *atual = sk->inicio;
    node **aux;
    aux = malloc((sk->nivelMAX + 1) * sizeof(node *));
    for (int i = 0; i <= sk->nivelMAX; i++)
        aux[i] = NULL;

    // Partindo do maior nível, vá para o próximo nó enquanto a chave for maior do que a do próximo nó
    // Caso contrário, insira o nó no array auxiliar, desça um nível e continue a busca
    for (int i = sk->nivel; i >= 0; i--) {
        while (atual->prox[i] != NULL && strcmp(atual->prox[i]->chave, chave) < 0) {
            atual = atual->prox[i];
        }
        aux[i] = atual;
    }

    // Acesse o nível 0 do próximo nó, que é onde a chave a ser removida deve estar
    atual = atual->prox[0];
    // Se tiver achado a chave a ser removida
    if (atual != NULL && strcmp(atual->chave, chave) == 0) {
        // Começando no nível 0, se o array auxiliar aponta para o nó a ser removido, faça ele apontar para o próximo nó (remoção de lista encadeada)
        for (int i = 0; i <= sk->nivel; i++) {
            if (aux[i]->prox[i] != atual)
                break;
            aux[i]->prox[i] = atual->prox[i];
        }

        // Remova os níveis sem elemento
        while (sk->nivel > 0 && sk->inicio->prox[sk->nivel] == NULL)
            sk->nivel--;

        free(atual->definicao);
        free(atual->chave);
        free(atual->prox);
        free(atual);
        free(aux);
        return 1;
    }
    free(aux);
    return 0;
}

void imprimeLista(Skiplist *sk, char inicial) {
    int haPalavras = 0;
    node *p = sk->inicio;
    while (p != NULL) {
        if (p->chave[0] == inicial) {
            haPalavras = 1;
            printf("%s ", p->chave);
            printf("%s\n", p->definicao);
        }
        p = p->prox[0];
    }
    if (haPalavras == 0) {
        printf("NAO HA PALAVRAS INICIADAS POR %c\n", inicial);
    }
}

int alteracao(Skiplist *sk, string chave, string novaDefinicao) {
    node *p = buscaSkipList(sk, chave);
    if(p == NULL) return 0;
    strcpy(p->definicao, novaDefinicao);
    return 1;
}