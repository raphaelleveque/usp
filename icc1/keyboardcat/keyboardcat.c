#include <stdio.h>

int main()
{
    char ordem_teclas[49];
    int caracteres_especiais[2];

    for (int i = 0; i < 49; i++)
    {
        scanf(" %c", &ordem_teclas[i]);
        switch (ordem_teclas[i])
        {
        case '_':
            caracteres_especiais[0] = i;
            break;
        case 'E':
            caracteres_especiais[1] = i;
            break;
        }
    }
    int tamanho;
    scanf("%d", &tamanho);
    int mensagem[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &mensagem[i]);
    }
    
 
    for (int i = 0; i < tamanho; i++)
    {
        if (caracteres_especiais[0] == mensagem[i])
        {
            printf(" ");
        }
        else if (caracteres_especiais[1] == mensagem[i])
        {
            printf("\n");
        }
        else
        {
        printf("%c", ordem_teclas[mensagem[i]]);
        }
    }
      
    return 0;
}