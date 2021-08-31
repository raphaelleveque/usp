#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"   // Já que usarei a struct definida no fracao.h, preciso importar este arquivo

fracao_t *criar(int num, int den)
{
    if (den == 0)
        return NULL;

    fracao_t *f = malloc(sizeof(fracao_t));

    f->num = num;
    f->den = den;
    
    return f;
}

void imprimir(fracao_t *f)
{
    if (f != NULL)
    {
        printf("%d/%d\n", f->num, f->den);
    }
}

void destruir(fracao_t *f)
{
    if (f != NULL)
    {
        free(f);
    }
}

int mdc(int a, int b)
{
    if(b == 0)
        return a;
    else
        return mdc(b, a % b);
}
int mmc(int a, int b)
{
    return a * b / mdc(a, b);
}

fracao_t *soma(fracao_t *f1, fracao_t *f2)
{
    // É necessário encontrar o MMC dos dois denominadores
    if (f1 == NULL || f2 == NULL) 
        return NULL;
    fracao_t *f = malloc(sizeof(fracao_t));
    f->den = mmc(f1->den, f2->den);
    f->num = (f->den / f1->den) * f1->num + (f->den / f2->den) * f2->num;

    return f;
}
