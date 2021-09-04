#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    pilha_t *p;
    p = create();
    
    for (int i = 0; i < 10; i++)
    {
        push(p, i);
    }
    
    int x;
    while (!isEmpty(p))
    {
        pop(p, &x);
        printf("%d ", x);
    }
}