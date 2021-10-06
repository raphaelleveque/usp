#include "conchas.h"

int main(){
    long nConchas;
    scanf("%ld", &nConchas);

    conchas_t *conchas = malloc(nConchas * sizeof(conchas_t));

    for (int i = 0; i < nConchas; ++i) {
        scanf("%lf ", &conchas[i].raio);
        conchas[i].nome = lendoString();
    }

    sort(conchas, nConchas);

    for (int i = 0; i < nConchas; ++i) {
        printf("%.3f %s\n", conchas[i].raio, conchas[i].nome);
        free(conchas[i].nome);
    }
    free(conchas);

    return 0;
}