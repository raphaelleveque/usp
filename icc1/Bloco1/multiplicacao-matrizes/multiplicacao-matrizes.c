#include <stdlib.h>
#include <stdio.h>

void valores_matriz (int l, int c, int matriz[l][c])
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matriz[i][j] = rand()%50 - 25;
        }
    }
    return;
}
    

int main()
{
    int semente, la, ca, lb, cb;

    scanf("%d %d", &la, &ca);
    scanf("%d %d", &lb, &cb);

    
    if (la <= 0 || lb <= 0 || cb <= 0 ||  ca <= 0 )
    {
        printf("Valores invalidos para a multiplicacao.\n");
        return 0;
    }

    if (ca != lb)
    {
        printf("Valores invalidos para a multiplicacao.\n");
        return 0;
    }

    scanf("%d", &semente);
    srand(semente);

    int matriza[la][ca], matrizb[lb][cb];
    
    valores_matriz(la, ca, matriza);
    valores_matriz(lb, cb, matrizb);

    int matrizc[la][cb];

    for (int i = 0; i < la; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            matrizc[i][j] = 0;
            for (int k = 0; k < ca; k++)
            {
                matrizc[i][j] += matriza[i][k] * matrizb[k][j];
            }  
        }      
    }

    for (int i = 0; i < la; i++)
    {
        printf("Linha %d: ", i);
        for (int j = 0; j < cb; j++)
        {
            printf("%d ", matrizc[i][j]);
        }
        printf("\n");
    }

    return 0;
}