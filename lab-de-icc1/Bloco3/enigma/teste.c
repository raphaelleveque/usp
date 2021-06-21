#include <stdio.h>

int main()
{
    int rotores[3][26];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            scanf("%d", &rotores[i][j]);
        }
    }

    int troca = rotores[0][0];
    for (int k = 0; k < 25; k++)
    {
        rotores[0][k] = rotores[0][k+1];
    }
    rotores[0][25] = troca;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            printf("%d ", rotores[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}