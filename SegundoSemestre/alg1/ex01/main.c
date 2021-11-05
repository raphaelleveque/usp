#include "frequentes.h"

int main(){
    palavras_t *palavras = NULL;

    int eof = 0;
    int fimDaLinha = 0;
    int palavrasTotais = 0;

    lerEntrada(palavras, &eof, &fimDaLinha, &palavrasTotais);

    return 0;
}