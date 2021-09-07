/*
    Raphael Leveque
    12542522
    SCC-02001
    Campo Minado
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

enum Opcoes
{
    Imprime = 1,
    Imprime_com_dicas = 2,
    controle_usuario = 3
};

typedef struct campoMinado
{
    int linhas;
    int colunas;
    char **matrizCampoMinado;
} CampoMinado;


char *lerLinha(FILE *fluxo, bool *possuiEOF);
void imprimirCampoMinado(CampoMinado *campoMinado);
void imprimeComDicas(CampoMinado *campoMinado);
int verificandoBombasProximas(CampoMinado *campoMinado, int i, int j);


int main()
{
    int opcao;
    scanf("%d", &opcao);

    bool possuiEOF = false;
    char *nomeArquivo = lerLinha(stdin, &possuiEOF);

    CampoMinado campoMinado;
    campoMinado.matrizCampoMinado = NULL;
    campoMinado.linhas = 0;
    campoMinado.colunas = 0;

    FILE *arquivo = fopen(nomeArquivo, "r");

    do
    {
        campoMinado.matrizCampoMinado = realloc(campoMinado.matrizCampoMinado, (campoMinado.linhas + 1) * sizeof(char *));
        campoMinado.matrizCampoMinado[campoMinado.linhas] = lerLinha(arquivo, &possuiEOF);
        campoMinado.colunas = strlen(campoMinado.matrizCampoMinado[0]);

        campoMinado.linhas++;
    } while (!possuiEOF);



    if (opcao == Imprime)
    {
        imprimirCampoMinado(&campoMinado);
    }
    else if (opcao == Imprime_com_dicas)
    {
        imprimeComDicas(&campoMinado);
    }

    return 0;
}

char *lerLinha(FILE *fluxo, bool *possuiEOF)
{
    scanf("%*[\n]s");
    char *string = malloc(sizeof(char));
    int caracteres = 0;
    int nmrMaxChar = 1;
    do
    {
        string[caracteres] = getc(fluxo);
        if (string[caracteres] == '\n' || string[caracteres] == EOF)
        {
            *possuiEOF = (string[caracteres] == EOF);
            string[caracteres] = '\0';
        }
        caracteres++;
        if (caracteres == nmrMaxChar)
        {
            nmrMaxChar *= 2;
            string = realloc(string, (nmrMaxChar) * sizeof(char));
        }

    } while (string[caracteres - 1] != '\0');

    string = realloc(string, (caracteres + 1) * sizeof(char));

    return string;
}

void imprimirCampoMinado(CampoMinado *campoMinado)
{
    for (int i = 0; i < campoMinado->linhas; i++)
    {
        for (int j = 0; j < campoMinado->colunas; j++)
        {
            printf("%c", campoMinado->matrizCampoMinado[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimeComDicas(CampoMinado *campoMinado)
{
    for (int i = 0; i < campoMinado->linhas; i++)
    {
        for (int j = 0; j < campoMinado->colunas; j++)
        {
            int quantidadeDeBombas = verificandoBombasProximas(campoMinado, i, j);

            if (quantidadeDeBombas > 0)
            {
                printf("%d", quantidadeDeBombas);
            }
            else
            {
                printf("%c", campoMinado->matrizCampoMinado[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int verificandoBombasProximas(CampoMinado *campoMinado, int i, int j)
{
    int quantidadeDeBombas = 0;
    if (campoMinado->matrizCampoMinado[i][j] != '*')
    {
        if (campoMinado->matrizCampoMinado[i - 1][j - 1] == '*')
        {
            quantidadeDeBombas++;
        }
        else if (campoMinado->matrizCampoMinado[i - 1][j] == '*')
        {
            quantidadeDeBombas++;
        }
        else if (campoMinado->matrizCampoMinado[i - 1][j + 1] == '*')
        {
            quantidadeDeBombas++;
        }
        else if (campoMinado->matrizCampoMinado[i][j - 1] == '*')
        {
            quantidadeDeBombas++;
        }
        else if (campoMinado->matrizCampoMinado[i][j + 1] == '*')
        {
            quantidadeDeBombas++;
        }
        else if (campoMinado->matrizCampoMinado[i + 1][j - 1] == '*')
        {
            quantidadeDeBombas++;
        }
        else if (campoMinado->matrizCampoMinado[i + 1][j] == '*')
        {
            quantidadeDeBombas++;
        }
        else if (campoMinado->matrizCampoMinado[i + 1][j + 1] == '*')
        {
            quantidadeDeBombas++;
        }
    }

    return quantidadeDeBombas;
}