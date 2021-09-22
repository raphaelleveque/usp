#include "primos.h"

int lendoNumeros(int quantidadePrimos, indices_t indices)
{
    int maiorIndice = 0;
    for (int i = 0; i < quantidadePrimos; i++)
    {
        scanf("%d", &indices[i]);
        if (indices[i] > maiorIndice)
        {
            maiorIndice = indices[i];
        }
    }
    return maiorIndice;
}


void encontrePrimos(primos_t primos, int maiorIndice)
{
    int i = 2;
    primos[1] = 2;
    primos[maiorIndice] = 0;
    int ePrimo = 1;
    for(int k = 3; primos[maiorIndice] == 0; k++)
    {
        for (int j = 1; j < i; j++)
        {
            if (k % primos[j] == 0)
            {
                ePrimo = 0;
                break;
            }
        }
        if (ePrimo)
        {
            primos[i] = k;
            i++;
        }
        ePrimo = 1;
    }
}