#include "frequentes.h"

string_t lerPalavra(int *fimDaLinha, int *eof){
    scanf("%*[\r\n]s");
    string_t string = malloc(sizeof(char));
    int caracteres = 0;
    int nmrMaxChar = 1;
    do{
        string[caracteres] = getchar();
        if (string[caracteres] == '\n'){
            *fimDaLinha = 1;
            if (string[caracteres - 1] == '\r')
                caracteres--;
            string[caracteres] = '\0';
        }
        else if (string[caracteres] == ' '){
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


void lerEntrada(palavras_t *palavras, int *eof, int *fimDaLinha, int *totalPalavras){
    int quantidadeImpressoes;
    while(!(*eof)) {
        while (!(*fimDaLinha)) {

            palavras = realloc(palavras, (*totalPalavras + 1) * sizeof (palavras_t));
            palavras[*totalPalavras].palavra = lerPalavra(fimDaLinha, eof);
            palavras[*totalPalavras].repeticoes = 0;
            palavras[*totalPalavras].visitada = 0;
            (*totalPalavras)++;
        }
        scanf("%d", &quantidadeImpressoes);
        char c = getchar();
        if (c == EOF)
            *eof = 1;
        if (quantidadeImpressoes > *totalPalavras){
            imprimindoPalavras(palavras, *totalPalavras, 0);
        }
        calculandoRepeticoes(palavras, totalPalavras);
        insertionSort(palavras, *totalPalavras);

        int palavrasRepetidas = 0;
        for (int i = 0; i < *totalPalavras; ++i)
            if (palavras[i].repeticoes == 0)
                palavrasRepetidas++;
        *totalPalavras = *totalPalavras - palavrasRepetidas;
        palavras = realloc(palavras, *totalPalavras * sizeof (palavras_t));
        ordenandoPorNome(palavras, *totalPalavras);

        if (*totalPalavras < quantidadeImpressoes)
            quantidadeImpressoes = *totalPalavras;
        imprimindoPalavras(palavras, quantidadeImpressoes, 1);
        *fimDaLinha = 0;
        *totalPalavras = 0;
        if (!(*eof))
            printf("\n");
    }

    for (int i = 0; i < *totalPalavras; i++)
    {
        free(palavras[i].palavra);
    }
    free(palavras);
}


void calculandoRepeticoes(palavras_t *palavras, int *totalPalavras){
    for (int i = 0; i < *totalPalavras; ++i) {
        for (int j = i; j < *totalPalavras; ++j) {
            if (strcmp(palavras[i].palavra, palavras[j].palavra) == 0 && palavras[j].visitada == 0){
                palavras[j].visitada = 1;
                palavras[i].repeticoes++;
            }
        }
    }
}

void insertionSort(palavras_t *palavras, int n){
    int i, j;
    palavras_t chave;
    for (i = 1; i < n; i++) {
        chave = palavras[i];

        j = i - 1;
        while (j >= 0 && palavras[j].repeticoes < chave.repeticoes) {
            palavras[j + 1] = palavras[j];

            j = j - 1;
        }
        palavras[j + 1] = chave;
    }

}


void ordenandoPorNome(palavras_t *palavras, int totalPalavras){
    palavras_t auxiliar;
    auxiliar.palavra = NULL;
    for (int i = 0; i < totalPalavras; ++i) {
        for (int j = i + 1; palavras[i].repeticoes == palavras[j].repeticoes; ++j) {
            if (strcmp(palavras[i].palavra, palavras[j].palavra) > 0){
                auxiliar = palavras[i];

                palavras[i] = palavras[j];

                palavras[j] = auxiliar;
            }
        }
    }
}



void imprimindoPalavras(palavras_t *palavras, int quantidadeImpressoes, int imprimirRepeticoes){
    for (int i = 0; i < quantidadeImpressoes; ++i){
        printf("%s", palavras[i].palavra);
        if (imprimirRepeticoes)
            printf(" %d\n", palavras[i].repeticoes);
        else
            printf("\n");
    }
}

