// Raphael Leveque 12542522
// SCC0201 — Introdução a Ciências da Computação II
// trabalho 3

#include "lista.h"

int main() {
    lista_t *l = criar();

    dados_t temporario;

    for (int i = 0; i < TAM; i++) {
        scanf("%d %d %d %d", &temporario.codigo, &temporario.tempoInicial, &temporario.volume, &temporario.prioridade);
        inserir(l, temporario);
    }
    escalonamento(l);
    liberar(l);

    return 0;
}