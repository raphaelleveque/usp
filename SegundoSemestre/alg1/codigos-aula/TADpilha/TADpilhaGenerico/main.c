#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct ponto
{
    int x, y;
} ponto_t;



int main()
{
    pilha_t *p;
    p = create(sizeof(ponto_t));

    ponto_t ponto;
    for (int i = 0; i < 10; i++)
    {
        ponto.x = i;
        ponto.y = -i;
        push(p, &ponto);  // Mando o endereço pois ela recebe um void*, e ponto é struct, não um ponteiro de struct
    }

    while (!isEmpty(p))
    {
        pop(p, &ponto);
        printf("(%2d, %2d)\n", ponto.x, ponto.y);
    }
    destroy(p);
    
}