#include "quickSort.h"

void imprimindoVetor(int *vet, int tam);

int main() {
    int tam;
    scanf("%d ", &tam);
    int *vet = malloc(sizeof(int) * tam);

    char c;
    c = getchar();

    for (int i = 0; i < tam; i++)
        scanf("%d", &vet[i]);

    switch (c) {
    case '1':
        uberSort(vet, 0, tam - 1, 1);
        break;
    case '2':
        srand(42);
        uberSort(vet, 0, tam - 1, 2);
        break;
    }
    imprimindoVetor(vet, tam);

    free(vet);
    return 0;
}

void imprimindoVetor(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d\n", vet[i]);
    }
}