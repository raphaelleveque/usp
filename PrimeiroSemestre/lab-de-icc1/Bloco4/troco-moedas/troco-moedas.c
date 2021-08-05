#include <stdio.h>

void troco_moedas(int *valor, int moedas_decrescente[6])
{
    if (*valor >= 100)
    {
        moedas_decrescente[0] = (*valor - (*valor % 100)) / 100;
        *valor = *valor % 100;
    }
    if (*valor >= 50)
    {
        moedas_decrescente[1] = (*valor - (*valor % 50)) / 50;
        *valor = *valor % 50;
    }
    if (*valor >= 25)
    {
        moedas_decrescente[2] = (*valor - (*valor % 25)) / 25;
        *valor = *valor % 25;
    }
    if (*valor >= 10)
    {
        moedas_decrescente[3] = (*valor - (*valor % 10)) / 10;
        *valor = *valor % 10;
    }
    if (*valor >= 5)
    {
        moedas_decrescente[4] = (*valor - (*valor % 5)) / 5;
        *valor = *valor % 5;
    }
    if (*valor >= 1)
    {
        moedas_decrescente[5] = *valor;
    }

}

int main()
{
    int valor;
    scanf("%d", &valor);

    int moedas_decrescente[6] = {};

    troco_moedas(&valor, moedas_decrescente);

    printf("O valor consiste em %d moedas de 1 real\n", moedas_decrescente[0]);
    printf("O valor consiste em %d moedas de 50 centavos\n", moedas_decrescente[1]);
    printf("O valor consiste em %d moedas de 25 centavos\n", moedas_decrescente[2]);
    printf("O valor consiste em %d moedas de 10 centavos\n", moedas_decrescente[3]);
    printf("O valor consiste em %d moedas de 5 centavos\n", moedas_decrescente[4]);
    printf("O valor consiste em %d moedas de 1 centavo\n", moedas_decrescente[5]);


    return 0;
}