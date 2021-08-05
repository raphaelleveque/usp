#include <stdio.h>

void maior(int numeros[10]);
void menor(int numeros[10]);
void media(int numeros[10]);
void moda(int numeros[10]);


void maior(int numeros[10])
{
    printf("%d ", numeros[9]);
}

void menor(int numeros[10])
{
    printf("%d ", numeros[0]);
}

void media(int numeros[10])
{
    double media = 0.0;

    for (int i = 0; i < 10; i++)
    {
        media += numeros[i];
    }
    media = media / 10;

    printf("%.2lf ", media);
}

void moda(int numeros[10])
{
    int contador[9] = {};
    for (int i = 0; i < 9;)
    {
        if (numeros[i] == numeros[i + 1])
        {
            int j = i + 1;
            while (numeros[i] == numeros[j])
            {
                j++;
            }
            contador[i] = j - (i + 1);
            i = j;
        }
        else
        {
            i++;
        }
        
    }
    

    int posicao;
    for (int i = 0, maior = contador[0]; i < 9; i++)
    {
        if (contador[i] > maior)
        {
            maior = contador[i];
            posicao = i;
        }
    }
    
    printf("%d\n", numeros[posicao]);
    
}


int main()
{
    int numeros[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &numeros[i]);
    }

    for (int i = 0, troca; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if (numeros[j] > numeros[i])
            {
                troca = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = troca;
            }
        }
    }
    
    maior(numeros);
    menor(numeros);
    media(numeros);
    moda(numeros);

    return 0;
}