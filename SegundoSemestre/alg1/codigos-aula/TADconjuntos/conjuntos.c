#include "conjuntos.h"

void criar_conjunto(elementos conjunto[TAMANHO_MAX])
{
    for (int i = 0; i < TAMANHO_MAX; i++)
    {
        conjunto[i] = 0;
        int random = rand() % TAMANHO_MAX;
        if (conjunto[random] == 0)
        {
            conjunto[random] = 1;
        }
    }
}

void imprime_conjunto(elementos conjunto[TAMANHO_MAX])
{
    printf("{");
    for (int i = 0; i < TAMANHO_MAX; i++)
    {
        if (conjunto[i] == 1)
        {
            printf("%d ", i);
        }
    }
    printf("}\n\n");
}

void interseccao(conjuntos_t *conjuntos)
{
    for (int i = 0; i < TAMANHO_MAX; i++)
    {
        conjuntos->interseccao[i] = 0;
        if (conjuntos->conjuntoA[i] == 1 && conjuntos->conjuntoB[i] == 1)
        {
            conjuntos->interseccao[i] = 1;
        }
    }
}

void uniao(conjuntos_t *conjuntos)
{
    for (int i = 0; i < TAMANHO_MAX; i++)
    {
        conjuntos->uniao[i] = 0;
        if (conjuntos->conjuntoA[i] == 1 || conjuntos->conjuntoB[i] == 1)
        {
            conjuntos->uniao[i] = 1;
        }
    }
}

void diferenca(conjuntos_t *conjuntos, char x)
{
    if (x == 'a')
    {
        for (int i = 0; i < TAMANHO_MAX; i++)
        {
            conjuntos->diferenca[i] = 0;
            if (conjuntos->conjuntoA[i] == 1 && conjuntos->conjuntoB[i] == 0)
            {
                conjuntos->diferenca[i] = 1;
            }
        }
    }
    else if(x == 'b')
    {
        for (int i = 0; i < TAMANHO_MAX; i++)
        {
            conjuntos->diferenca[i] = 0;
            if (conjuntos->conjuntoB[i] == 1 && conjuntos->conjuntoA[i] == 0)
            {
                conjuntos->diferenca[i] = 1;
            }
        }
    }
}