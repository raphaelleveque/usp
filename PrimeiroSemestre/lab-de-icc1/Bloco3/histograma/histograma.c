#include <stdio.h>

int main()
{
    int cores[5] = {}, frequencia[25];
    for (int i = 0; i < 25; i++)
    {
        scanf("%d", &frequencia[i]);
        cores[frequencia[i]]++;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d: |", i);
        for (int j = 0; j < cores[i]; j++)
        {
            printf("#");
        }
        printf("\n");
    }

    int cor_mais_frequente = 0;
    for (int i = 0, mais_frequente = 0; i < 5; i++)
    {
        if (cores[i] > mais_frequente)
        {
            mais_frequente = cores[i];
            cor_mais_frequente = i;
        } 
    }

    for (int i = 0; i < 25; i++)
    {
        if (frequencia[i] == cor_mais_frequente)
        {
            printf("%d\n", i);
        }
    }  
    return 0;
}