// Raphael Leveque 12542522
#include <stdio.h>
#include <stdlib.h>

#define CELULA_MORTA '.'
#define CELULA_VIVA 'x'

typedef struct matrizes
{
    int linhas, colunas;
    char ** matriz;

} Matrizes;

void lerMatriz(Matrizes * matrizOriginal);
void copiandoMatriz(Matrizes * matriz1, Matrizes matriz2);
void calculoGeracoes(Matrizes * matrizOriginal, char metricaVizinhanca);
int checagemVizinhanca(int linha, int coluna, Matrizes matriz, char metricaVizinhanca);


int main()
{
    Matrizes matrizOriginal;
    scanf("%d %d", &matrizOriginal.linhas, &matrizOriginal.colunas);

    int numeroGeracoes;
    scanf("%d", &numeroGeracoes);

    if (matrizOriginal.linhas <= 0 || matrizOriginal.colunas <= 0 || numeroGeracoes <= 0)
    {
        printf("Dados de entrada apresentam erro.\n");
        return 0;
    }

    char metricaVizinhanca;
    scanf("%*[\r\n]s");
    scanf("%c", &metricaVizinhanca);
    scanf("%*[\r\n]s");

    if (metricaVizinhanca != 'M' && metricaVizinhanca != 'N')
    {
        printf("Dados de entrada apresentam erro.\n");
        return 0;
    }
    

    matrizOriginal.matriz = malloc(matrizOriginal.linhas * sizeof(char *));
    for (int i = 0; i < matrizOriginal.linhas; i++)
    {
        matrizOriginal.matriz[i] = malloc(matrizOriginal.colunas * sizeof(char));
    }
    lerMatriz(&matrizOriginal);


    for (int i = 0; i < numeroGeracoes; i++)
    {
        calculoGeracoes(&matrizOriginal, metricaVizinhanca);
    }
    
    

    return 0;
}

void lerMatriz(Matrizes * matrizOriginal)
{
    for (int i = 0; i < matrizOriginal->linhas; i++)
    {
        for (int j = 0; j < matrizOriginal->colunas; j++)
        {
            matrizOriginal->matriz[i][j] = getchar();
        }
        scanf("%*[\r\n]s");
    }
}

void copiandoMatriz(Matrizes * matriz1, Matrizes matriz2)
{
    for (int i = 0; i < matriz2.linhas; i++)
    {
        for (int j = 0; j < matriz2.colunas; j++)
        {
            matriz1->matriz[i][j] = matriz2.matriz[i][j];
        }
    }
}

void calculoGeracoes(Matrizes * matrizOriginal, char metricaVizinhanca)
{
    Matrizes matrizCopia;
    copiandoMatriz(&matrizCopia, * matrizOriginal);

    for (int i = 0; i < matrizCopia.linhas; i++)
    {
        for (int j = 0; j < matrizCopia.colunas; j++)
        {
            int vizinhos = checagemVizinhanca(i, j, * matrizOriginal, metricaVizinhanca);

            if (matrizOriginal->matriz[i][j] == CELULA_MORTA)
            {
                if (vizinhos == 3)
                {
                    matrizCopia.matriz[i][j] = CELULA_VIVA;
                }
            }
            else if (matrizOriginal->matriz[i][j] == CELULA_VIVA)
            {
                if (vizinhos < 2)
                {
                    matrizCopia.matriz[i][j] = CELULA_MORTA;
                }
                else if (vizinhos > 3)
                {
                    matrizCopia.matriz[i][j] = CELULA_MORTA;
                }
            }
        }
    }
    copiandoMatriz(matrizOriginal, matrizCopia);
}

int checagemVizinhanca(int linhaAtual, int colunaAtual, Matrizes matriz, char metricaVizinhanca)
{
    int numeroCelulasVivas = 0;

    int totalLinhas = matriz.linhas;
    int totalColunas = matriz.colunas;

    if (metricaVizinhanca == 'M')
    {
        for (int i = 0; i < 3; i++)
        {
            if (matriz.matriz[(totalLinhas + linhaAtual - 1 + i) % totalLinhas][(totalColunas + colunaAtual - 1) % totalColunas]
            == CELULA_VIVA)
            {
                numeroCelulasVivas++;
            }
            if (matriz.matriz[(totalLinhas + linhaAtual - 1 + i) % totalLinhas][(totalColunas + colunaAtual + 1) % totalColunas] 
            == CELULA_VIVA)
            {
                numeroCelulasVivas++;
            }
            if (matriz.matriz[(totalLinhas + linhaAtual - 1) % totalLinhas][(totalColunas + colunaAtual - 1 + i) % totalColunas] 
            == CELULA_VIVA)
            {
                numeroCelulasVivas++;
            }
            if (matriz.matriz[(totalLinhas + linhaAtual + 1) % totalLinhas][(totalColunas + colunaAtual - 1 + i) % totalColunas] 
            == CELULA_VIVA)
            {
                numeroCelulasVivas++;
            }
        }
        return numeroCelulasVivas;
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            if (matriz.matriz[(totalLinhas + linhaAtual - 2 + i) % totalLinhas][colunaAtual] == CELULA_VIVA)
            {
                numeroCelulasVivas++;
            }
            if (matriz.matriz[(totalLinhas + linhaAtual + 2 - i) % totalLinhas][colunaAtual] == CELULA_VIVA)
            {
                numeroCelulasVivas++;
            }
            if (matriz.matriz[linhaAtual][(totalColunas + colunaAtual - 2 + i) % totalColunas] == CELULA_VIVA)
            {
                numeroCelulasVivas++;
            }
            if (matriz.matriz[linhaAtual][(totalColunas + colunaAtual + 2 - i) % totalColunas] == CELULA_VIVA)
            {
                numeroCelulasVivas++;
            }
        }
        return numeroCelulasVivas;
    }
}

