#include "conchas.h"



string_t lendoString(){
    string_t string = malloc(sizeof(char));
    int caracteres = 0;
    int nmrMaxChar = 1;
    do{
        string[caracteres] = getchar();
        if (string[caracteres] == '\n' || string[caracteres] == EOF){
            if (string[caracteres - 1] == '\r')
                caracteres--;
            string[caracteres] = '\0';
        }
        caracteres++;
        if (caracteres == nmrMaxChar){
            nmrMaxChar *= 2;
            string = realloc(string, (nmrMaxChar) * sizeof(char));
        }

    }while (string[caracteres-1] != '\0');
    string = realloc(string, (caracteres + 1) * sizeof(char));

    return string;
}


void sort(conchas_t *conchas, long nConchas){
    for (long k = nConchas / 2; k >= 1; k /= 2){
        for (long i = k; i < nConchas; i++){
            conchas_t temp = conchas[i];

            long j = i;
            while (j >= k && conchas[j - k].raio > temp.raio){
                conchas[j] = conchas[j - k];
                j -= k;
            }
            conchas[j] = temp;
        }
    }
}  