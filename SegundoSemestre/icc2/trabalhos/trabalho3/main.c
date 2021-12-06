// Raphael Leveque 12542522
// SCC0201 — Introdução a Ciências da Computação II
// trabalho 3

#include "lista.h"

int main() {
    lista_t *l = criar();

    int i = 0;
    dados_t temporario;

    while (i < 4) {
        //ungetc(c, stdin);
        scanf("%d %d %d %d", &temporario.codigo, &temporario.tempoInicial, &temporario.volume, &temporario.prioridade);
        inserir(l, temporario);
        i++;
    }

    return 0;
}