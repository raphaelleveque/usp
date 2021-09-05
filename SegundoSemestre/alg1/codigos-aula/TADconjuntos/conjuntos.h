#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO_MAX 100

typedef int elementos;

typedef struct conjuntos
{
    elementos conjuntoA[TAMANHO_MAX];
    elementos conjuntoB[TAMANHO_MAX];
    elementos interseccao[TAMANHO_MAX];
    elementos uniao[TAMANHO_MAX];
    elementos diferenca[TAMANHO_MAX];
} conjuntos_t;


void criar_conjunto(elementos conjunto[TAMANHO_MAX]);
void imprime_conjunto(elementos conjunto[TAMANHO_MAX]);
void interseccao(conjuntos_t *conjuntos);
void uniao(conjuntos_t *conjuntos);
void diferenca(conjuntos_t *conjuntos, char x);
