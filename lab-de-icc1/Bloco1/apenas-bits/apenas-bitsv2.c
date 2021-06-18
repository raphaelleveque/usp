#include <stdio.h>

int main()
{
    unsigned int entrada, teste;
    char saida;

    //Entrada
    printf("Entrada: ");
    scanf("%d",&entrada);

    printf("Saída: ");


    for (int i = 0; i < 4; i++)
    {
        teste = entrada & 255;
        entrada = entrada >> 8;
        printf("%c", teste);
    }
    

    return 0;
}