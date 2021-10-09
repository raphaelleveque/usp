#include "lista.h"

int main(){
    int nCasos;
    scanf("%d", &nCasos);

    int tamanho, nRotacoes;
    for (int i = 0; i < nCasos; ++i) {
        lista_t *l = cria();
        scanf("%d", &tamanho);
        scanf("%d", &nRotacoes);
        for (int j = 0; j < tamanho; ++j) {
            int tmp;
            scanf("%d", &tmp);
            insere(l, tmp);
        }
        rotaciona(l, nRotacoes);
        imprimir(l);
        liberar(l);
    }

    return 0;
}