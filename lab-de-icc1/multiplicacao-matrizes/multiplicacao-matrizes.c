#include <stdlib.h>
#include <stdio.h>

void valores_matriz (int matriz[][], int l, int c)
{

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matriz[i][j] = rand()%50 - 25;
        }
    }
    return matriz[l][c];
}
    

int main()
{
    int semente, la, ca, lb, cb;
    int matrizc[1000][1000];

    scanf("%d %d", &la, &ca);
    scanf("%d %d", &lb, &cb);

    if (ca != lb)
    {
        printf("Valores invalidos para a multiplicacao .\n");
        return 0;
    }

    scanf("%d", &semente);
    srand(semente);

    int matriza[la][ca], matrizb[lb][cb];

    for (int i = 0; i < la; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            matriza[i][j] = rand()%50 - 25;
        }
    }
    for (int i = 0; i < lb; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            matrizb[i][j] = rand()%50 - 25;
        }  
    }
    


    for (int i = 0; i < la; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            for (int k = 0, h = 0; k < ca, h < lb; k++, h++)
            {
                matrizc[i][j] += matriza[i][k] * matrizb[h][j];
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