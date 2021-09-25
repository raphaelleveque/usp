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
    //printf("%s\n", string);

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
    int i, chave, j;
    int visitadoAuxiliar;
    string_t palavraAuxiliar = NULL;
    for (i = 1; i < n; i++) {
        chave = palavras[i].repeticoes;
        visitadoAuxiliar = palavras[i].visitada;
        palavraAuxiliar = realloc(palavraAuxiliar, (strlen(palavras[i].palavra) + 1) * sizeof (char));
        strcpy(palavraAuxiliar, palavras[i].palavra);

        j = i - 1;

        while (j >= 0 && palavras[j].repeticoes < chave) {
            palavras[j + 1].repeticoes = palavras[j].repeticoes;
            palavras[j + 1].visitada = palavras[j].visitada;
            palavras[j + 1].palavra = realloc(palavras[j + 1].palavra, (strlen(palavras[j].palavra) + 1) * sizeof (char));
            strcpy(palavras[j + 1].palavra, palavras[j].palavra);

            j = j - 1;
        }
        palavras[j + 1].repeticoes = chave;
        palavras[j + 1].visitada = visitadoAuxiliar;
        palavras[j + 1].palavra = realloc(palavras[j + 1].palavra, (strlen(palavraAuxiliar) + 1) * sizeof (char));
        strcpy(palavras[j + 1].palavra, palavraAuxiliar);
    }

    free(palavraAuxiliar);
}


void ordenandoPorNome(palavras_t *palavras, int totalPalavras){
    palavras_t auxiliar;
    for (int i = 0; i < totalPalavras; ++i) {
        for (int j = i + 1; palavras[i].repeticoes == palavras[j].repeticoes; ++j) {
            if (strcmp(palavras[i].palavra, palavras[j].palavra) > 0){
                auxiliar.repeticoes = palavras[i].repeticoes;
                auxiliar.visitada = palavras[i].visitada;
                auxiliar.palavra = realloc(auxiliar.palavra, (strlen(palavras[i].palavra) + 1) * sizeof (char));
                strcpy(auxiliar.palavra, palavras[i].palavra);

                palavras[i].repeticoes = palavras[j].repeticoes;
                palavras[i].visitada = palavras[j].visitada;
                palavras[i].palavra = realloc(palavras[i].palavra, (strlen(palavras[j].palavra) + 1) * sizeof (char));
                strcpy(palavras[i].palavra, palavras[j].palavra);

                palavras[j].repeticoes = auxiliar.repeticoes;
                palavras[j].visitada = auxiliar.visitada;
                palavras[j].palavra = realloc(palavras[j].palavra, (strlen(auxiliar.palavra) + 1) * sizeof(char));
                strcpy(palavras[j].palavra, auxiliar.palavra);
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

