// SKIPLIST.H 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Skiplist Skiplist;
typedef struct NO node;
typedef char* string;

struct NO {
    string chave;
    string definicao;
    // vetor de ponteiros; Cada elemento desse vetor aponta para um novo nível
    struct NO **prox;
};

struct Skiplist {
    int nivelMAX;
    // p = probabilidade do nó ser sorteado
    double p;
    int nivel;
    node *inicio;
};

Skiplist* cria(int nivelMAX, double p);
node* novoNo(string chave, int nivel, string definicao);
void liberaSkiplist(Skiplist *sk);
node* buscaSkipList(Skiplist *sk, string chave);
int insereSkipList(Skiplist *sk, string chave, string definicao);
int sorteiaNivel (Skiplist *sk);
int removeSkiplist(Skiplist *sk, string chave);
void imprimeLista(Skiplist *sk, char inicial);
int alteracao(Skiplist *sk, string chave, string novaDefinicao);