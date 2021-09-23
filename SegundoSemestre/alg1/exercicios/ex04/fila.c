#include "fila.h"


string_t lerPalavra()
{    
    scanf("%*[\r\n]s");
    string_t string = malloc(sizeof(char));
    int caracteres = 0;
    int nmrMaxChar = 1;
    do
    {
        string[caracteres] = getchar();
        if (string[caracteres] == '\n' || string[caracteres] == EOF || string[caracteres] == ' ')
        {
            if (string[caracteres - 1] == '\r')
            {
                caracteres--;
            }
            string[caracteres] = '\0';
        }
        caracteres++;
        if (caracteres == nmrMaxChar)
        {
            nmrMaxChar *= 2;
            string = realloc(string, (nmrMaxChar) * sizeof(char));
        }

    }while (string[caracteres-1] != '\0');
    string = realloc(string, (caracteres + 1) * sizeof(char));

    return string;
}


pessoa_t* entra(int *quantidadePessoas, pessoa_t *pessoas)
{
    (*quantidadePessoas)++;
    pessoas = realloc(pessoas, *quantidadePessoas * sizeof(pessoa_t));
    pessoas[*quantidadePessoas - 1].nome = lerPalavra();
    scanf("%d", &pessoas[*quantidadePessoas - 1].idade);
    scanf("%d", &pessoas[*quantidadePessoas - 1].condicao);

    if (pessoas[*quantidadePessoas - 1].idade >= 60 && pessoas[*quantidadePessoas - 1].condicao)
    {
        pessoas[*quantidadePessoas - 1].prioridade = 1;
    }
    else if (pessoas[*quantidadePessoas - 1].condicao)
    {
        pessoas[*quantidadePessoas - 1].prioridade = 2;
    }
    else if (pessoas[*quantidadePessoas - 1].idade >= 60)
    {
        pessoas[*quantidadePessoas - 1].prioridade = 3;
    }
    else
    {
        pessoas[*quantidadePessoas - 1].prioridade = 4;
    }
    return pessoas;
}


void checarPrioridade(pessoa_t *pessoas, int quantidadePessoas)
{
    if (quantidadePessoas == 1)
    {
        return;
    }
    
    for (int i = quantidadePessoas - 1; i > 0; i--)
    {
        if (pessoas[i].prioridade < pessoas[i - 1].prioridade)
        {
            filaAnda(pessoas, i, -1);
        }   
    }
}


void filaAnda(pessoa_t *pessoas, int posicao, int direitaOuEsquerda)
{
    string_t nomeTemporario = malloc((strlen(pessoas[posicao].nome) + 1) * sizeof(char));
    strcpy(nomeTemporario, pessoas[posicao].nome);
    int idadeTemporaria = pessoas[posicao].idade;
    int condicaoTemporaria = pessoas[posicao].condicao;
    int prioridadeTemporaria = pessoas[posicao].prioridade;

    strcpy(pessoas[posicao].nome, pessoas[posicao + direitaOuEsquerda].nome);
    pessoas[posicao].idade = pessoas[posicao + direitaOuEsquerda].idade;
    pessoas[posicao].condicao = pessoas[posicao + direitaOuEsquerda].condicao;
    pessoas[posicao].prioridade = pessoas[posicao + direitaOuEsquerda].prioridade;

    strcpy(pessoas[posicao + direitaOuEsquerda].nome, nomeTemporario);
    pessoas[posicao + direitaOuEsquerda].idade = idadeTemporaria;
    pessoas[posicao + direitaOuEsquerda].condicao = condicaoTemporaria;
    pessoas[posicao + direitaOuEsquerda].prioridade = prioridadeTemporaria;

    free(nomeTemporario);
}


pessoa_t* sai(int *quantidadePessoas, pessoa_t *pessoas)
{
    if ((*quantidadePessoas) == 0)
    {
        printf("FILA VAZIA\n");
        return pessoas;
    }

    printf("%s %d %d\n", pessoas[0].nome, pessoas[0].idade, pessoas[0].condicao);
    (*quantidadePessoas)--;
    for (int i = 0; i < *quantidadePessoas; i++)
    {
        filaAnda(pessoas, i, 1);
    }
    free(pessoas[*quantidadePessoas].nome);
    pessoas = realloc(pessoas, *quantidadePessoas * sizeof(pessoa_t));
    
    return pessoas;

}