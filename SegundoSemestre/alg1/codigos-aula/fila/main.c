#include <stdio.h>
#include "fila.h"

int main()
{
    fila_t *f;
    f = criar();
    elem x;
    for (int i = 0; i < Tam; i++)
    {
        inserir(f, i);
    }

    while (!isEmpty(f))
    {
        remover(f, &x);
    }

    return 0;
}