#include <stdio.h>

int main()
{
    char texto;
    int caracteres = 0, palavras = 0, linhas = 0;
    int estado_palavra = 0; 

    while ((texto = getchar()) != EOF)
    {
        caracteres++;
        if (texto == '\n')
        {
            linhas++;
        }
        if (texto == '\n' || texto == '\r' || texto == ' ' || texto == '\t')
        {
            estado_palavra = 0;
        }
        else if (!estado_palavra)
        {
            palavras++;
            estado_palavra = 1;
        }    
               
    }
    printf("Linhas\tPalav.\tCarac.\n");  
    printf("%d\t%d\t%d", linhas, palavras, caracteres);

    return 0;
}