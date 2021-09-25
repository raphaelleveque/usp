#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string_t;
typedef struct {
    string_t palavra;
    int repeticoes;
    int visitada;
} palavras_t;

string_t lerPalavra(int *fimDaLinha, int *eof);
void lerEntrada(palavras_t *palavras, int *eof, int *fimDaLinha, int *totalPalavras);
void calculandoRepeticoes(palavras_t *palavras, int *totalPalavras);
void insertionSort(palavras_t *palavras, int n);
void ordenandoPorNome(palavras_t *palavras, int totalPalavras);
void imprimindoPalavras(palavras_t *palavras, int quantidadeImpressoes, int imprimirRepeticoes);