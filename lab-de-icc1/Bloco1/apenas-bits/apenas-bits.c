#include <stdio.h>

int main()
{
    unsigned int entrada, vetor[4], teste;

    //Entrada
    scanf("%d",&entrada);



    for (int i = 0; i < 4; i++)
    {
        teste = entrada & 255;
        entrada = entrada >> 8;
        vetor[i] = teste;
    }  
    
    printf("%c", vetor[3]);
    printf("%c", vetor[2]);
    printf("%c", vetor[1]);
    printf("%c", vetor[0]);

    return 0;
}


