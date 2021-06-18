#include <stdio.h>

int main()
{
    int altura, numero_caracteres = 1; 
    char caractere;

    scanf("%d %c", &altura, &caractere);

    if (altura > 25 || altura <= 0)
    {
        printf("Altura invalida\n");
    }
    else 
    {
        for (int i = 0; i < altura + i; i++)
        {
            for (int i = 0; i < (altura - 1); i++)
            {
                printf(" ");
            }
            

            for (int i = 0; i < numero_caracteres; i++)
            {
                printf("%c", caractere);
            }
            numero_caracteres += 2;
            altura--;
            printf("\n");
        }
    }

    return 0;
}

