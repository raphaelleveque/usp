/*
Nome: João Pedro Duarte Nunes
Nº USP: 12542460
Disciplina: SCC0201
Trabalho: Campo Minado
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum Opcoes
{
    imprimir = 1,
    imprimeComDicas = 2,
    controleUsuario = 3
};

typedef struct
{
    char **tabuleiro;
    int linhas, colunas;
    char pixelVelho;
} infosTabuleiro;

char *read_line(FILE *stream)
{
    char *linhaMatriz = NULL;
    int tamanhoLinha = 0;

    do
    {
        linhaMatriz = realloc(linhaMatriz, ++tamanhoLinha * sizeof(char));
        linhaMatriz[tamanhoLinha - 1] = fgetc(stream);
    } while (linhaMatriz[tamanhoLinha - 1] != EOF && linhaMatriz[tamanhoLinha - 1] != '\n');
    
    if (linhaMatriz[tamanhoLinha - 1] == EOF)
    {
    linhaMatriz[tamanhoLinha - 1] = '\0';
    }
    

    return linhaMatriz;
}

void opcao1(infosTabuleiro informacoes)
{
    //Imprimir
    for (int i = 0; i < informacoes.linhas; i++)
    {
        for (int j = 0; j < informacoes.colunas; j++)
        {
            printf("%c", informacoes.tabuleiro[i][j]);
        }
    }
}

void opcao2(infosTabuleiro informacoes)
{
}

void opcao3(infosTabuleiro informacoes)
{
}

int main()
{

    int opcoes;

    infosTabuleiro infos;
    infos.tabuleiro = NULL;
    infos.linhas = 0;
    infos.colunas = 0;
    infos.pixelVelho = '\0';
    //Registrar input do usuário
    scanf("%i", &opcoes);
    getchar();

    char *nomeArquivo = NULL;

    nomeArquivo = read_line(stdin);

    FILE *file = fopen(nomeArquivo, "r");

    //Ler o arquivo
    while (!feof(file))
    {
        infos.tabuleiro = realloc(infos.tabuleiro, (++infos.linhas) * sizeof(char *));
        infos.tabuleiro[infos.linhas - 1] = read_line(file);
    }
    infos.colunas = strlen(infos.tabuleiro[0]);

    //infos.tabuleiro[infos.linhas - 1][infos.colunas] = '\0';

    //Opção 1:
    if (opcoes == imprimir)
    {
        opcao1(infos);
    }
    if (opcoes == imprimeComDicas)
    {
        opcao2(infos);
    }
    if (opcoes == controleUsuario)
    {
        opcao3(infos);
    }

    fclose(file);
    
    for (int i = 0; i < infos.linhas; i++)
    {
        free(infos.tabuleiro[i]);
    }
    free(infos.tabuleiro);
    free(nomeArquivo);

    return 0;
}