#include "quickSort.h"

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Essa função ordena o vetor com o UberSort
void uberSort(int *vetor, int inicio, int fim, int modo) {
    if (fim - inicio + 1 <= 10) {
        insertionSort(vetor, inicio, fim);
        return;
    }

    pivot(vetor, inicio, fim, modo);
    int dir = fim - 1;

    int esq = inicio;
    int mid = inicio;

    while (mid <= dir) {
        if (vetor[fim] > vetor[mid])
            swap(&vetor[mid++], &vetor[esq++]);
        else if (vetor[fim] < vetor[mid])
            swap(&vetor[mid], &vetor[dir--]);
        else
            mid++;
    }

    swap(&vetor[fim], &vetor[mid]);

    uberSort(vetor, inicio, esq - 1, modo);
    uberSort(vetor, mid + 1, fim, modo);
}

// Essa função encontra o pivo dependendo de qual caso o usuário escolheu, escolhendo ou a mediana ou aleatoriamente
void pivot(int *vetor, int inicio, int fim, int modo) {
    if (modo == 1) {
        int meio = (inicio + fim) / 2.0;

        if (vetor[meio] >= vetor[inicio] && vetor[meio] <= vetor[fim]) {
            swap(&vetor[meio], &vetor[fim]);
            return;
        }
        if (vetor[inicio] > vetor[fim] && vetor[inicio] < vetor[meio]) {
            swap(&vetor[inicio], &vetor[fim]);
            return;
        }
        return;
    }
    if (modo == 2) {
        swap(&vetor[inicio + rand() % (fim - inicio)], &vetor[fim]);
        return;
    }
    exit(EXIT_FAILURE);
}

void insertionSort(int v[], int ini, int fim) {
    for (int i = ini + 1; i <= fim; ++i) {
        int chave = v[i];
        int j = i - 1;
        while (j >= ini && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}