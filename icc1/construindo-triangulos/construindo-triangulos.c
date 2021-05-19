#include <stdio.h>

int main()
{
    int altura, numero_caracteres = 1; 
    char caractere;

    scanf("%d %c", &altura, &caractere);

    if (altura > 25)
    {
        printf("Altura invalida\n");
    }
    else 
    {
        for (int i = 0; i < altura; i++)
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



/*
printf("%*s", altura-1, "");
            printf("%*s", numero_caracteres, caractere);
            printf("\n");
            numero_caracteres += i;

*/

/*

 a

*/