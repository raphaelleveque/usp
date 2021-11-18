#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int tam, int v[tam]){
    for (int i = 0; i < tam - 1; ++i) {
        int swap = 0;
        for (int j = 0; j < tam - 1; ++j) {
            if (v[j] > v[j + 1]){
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
                swap = 1;
            }
        }
        if (swap == 0) break;
    }
}

void insertionSort(int n, int v[n]){
    for (int i = 1; i < n; ++i) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}
void reverseInsertionSort(int n, int v[n]){
    for (int i = 1; i < n; ++i) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] < chave){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}




void merge(int v[], int esq, int meio, int dir){
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int vEsq[n1], vDir[n2];
    int k = esq;

    for (int i = 0; i < n1; i++, k++)
        vEsq[i] = v[k];
    for (int i = 0; i < n2; i++, k++)
        vDir[i] = v[k];

    int topoEsquerda = 0;
    int topoDireita = 0;
    k = esq;

    while (topoEsquerda < n1 && topoDireita < n2){
        if (vEsq[topoEsquerda] <= vDir[topoDireita]){
            v[k] = vEsq[topoEsquerda];
            topoEsquerda++;
        }
        else{
            v[k] = vDir[topoDireita];
            topoDireita++;
        }
        k++;
    }
    while (topoEsquerda < n1){
        v[k] = vEsq[topoEsquerda];
        topoEsquerda++;
        k++;
    }
    while (topoDireita < n2) {
        v[k] = vDir[topoDireita];
        topoDireita++;
        k++;
    }
}



void mergeSort(int v[], int esq, int dir){
    if (esq >= dir) return;

    int meio = (int)((esq + dir) / 2.0);
    mergeSort(v, esq, meio);
    mergeSort(v, meio + 1, dir);

    merge(v, esq, meio, dir);
}


void printandoVetor(int n, int v[n]){
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void rodandoNums(int tam, int v[], FILE *csv, int op, int melhor){
    double tempoTotal = 0.0;
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < tam; ++j) {
            v[j] = rand() % 10000;
        }
        if(!melhor)
            reverseInsertionSort(tam, v);
        else
            insertionSort(tam, v);
        clock_t start_t, end_t;
        start_t = clock();
        if (op == 0)
            bubbleSort(tam, v);
        else if (op == 1)
            insertionSort(tam, v);
        else
            mergeSort(v, 0, tam - 1);
        end_t = clock();
        tempoTotal += (double)(end_t - start_t) / CLOCKS_PER_SEC;
    }
    fprintf(csv, "%-8d, ", tam);
    fprintf(csv, "%.8lf\n", (double)(tempoTotal / (double)30.0));
}




int main(){
    srand(time(NULL));
    FILE *csv = fopen("melhor-pior2.txt", "w");

    fprintf(csv, "Melhor Caso:\n");
    int tam25 = 25, tam100 = 100, tam1000 = 1000, tam10000 = 10000;
    int v25[tam25], v100[tam100], v1000[tam1000], v10000[tam10000];


    for (int j = 0; j < 3; ++j) {
        if (j == 0)
            fprintf(csv, "Bubble Sort:\n");
        else if (j == 1)
            fprintf(csv, "Insertion Sort:\n");
        else
            fprintf(csv, "Merge Sort:\n");
        for (int i = 0; i < 4; ++i) {
            if (i == 0)
                rodandoNums(tam25, v25, csv, j, 1);
            else if (i == 1){
                rodandoNums(tam100, v100, csv, j, 1);
                int *vk = malloc(500 * sizeof(int));
                rodandoNums(500, vk, csv, j, 1);
                free(vk);
            }
            else if (i == 2)
                rodandoNums(tam1000, v1000, csv, j, 1);
            else{
                for (int k = 2; k <= 10; ++k) {
                    int *vk = malloc(k*1000*sizeof(int));
                    rodandoNums(k*1000, vk, csv, j, 1);
                    free(vk);
                }

            }
        }
    }


    fprintf(csv, "\nPior Caso:\n");

    for (int j = 0; j < 3; ++j) {
        if (j == 0)
            fprintf(csv, "Bubble Sort:\n");
        else if (j == 1)
            fprintf(csv, "Insertion Sort:\n");
        else
            fprintf(csv, "Merge Sort:\n");
        for (int i = 0; i < 4; ++i) {
            if (i == 0)
                rodandoNums(tam25, v25, csv, j, 0);
            else if (i == 1){
                rodandoNums(tam100, v100, csv, j, 0);
                int *vk = malloc(500 * sizeof(int));
                rodandoNums(500, vk, csv, j, 0);
                free(vk);
            }
            else if (i == 2)
                rodandoNums(tam1000, v1000, csv, j, 0);
            else{
                for (int k = 2; k <= 10; ++k) {
                    int *vk = malloc(k*1000*sizeof(int));
                    rodandoNums(k*1000, vk, csv, j, 0);
                    free(vk);
                }

            }
        }
    }
    fclose(csv);
    


    return 0;
}