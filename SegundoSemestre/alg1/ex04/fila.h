#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string_t;

typedef struct pessoa
{
    string_t nome;
    int idade;
    int condicao;
    int prioridade;
} pessoa_t;


string_t lerPalavra();
pessoa_t* entra(int *quantidadePessoas, pessoa_t *pessoas);
void checarPrioridade(pessoa_t *pessoas, int quantidadePessoas);
void filaAnda(pessoa_t *pessoas, int posicao, int direitaOuEsquerda);
pessoa_t* sai(int *quantidadePessoas, pessoa_t *pessoas);