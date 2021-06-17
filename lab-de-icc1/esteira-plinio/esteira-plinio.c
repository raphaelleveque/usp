#include <stdio.h>

int main()
{
    char esteira[32][32];
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            scanf(" %c", &esteira[i][j]);
        }
    }

    printf("\n\n\n\n");

    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            printf("%c", esteira[i][j]);
        }
    }
    
    

    return 0;
}