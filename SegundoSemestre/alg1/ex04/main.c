#include "fila.h"


int main()
{
    int acoes;
    scanf("%d", &acoes);
    
    int quantidadePessoas = 0;
    string_t acao;
    pessoa_t *pessoas = NULL;    

    for (int i = 0; i < acoes; i++)
    {
        acao = lerPalavra();
        if (strcmp(acao, "ENTRA") == 0)
        {
            pessoas = entra(&quantidadePessoas, pessoas);
            checarPrioridade(pessoas, quantidadePessoas);
        }
        else if(strcmp(acao, "SAI") == 0)
        {
            pessoas = sai(&quantidadePessoas, pessoas);
        }
        else
        {
            printf("%s\n", acao);
        }
        free(acao);
    }

    for (int i = 0; i < quantidadePessoas; i++)
    {
        free(pessoas[i].nome);
    }
    free(pessoas);
    
    return 0;
}