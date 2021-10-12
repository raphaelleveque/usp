/*
* Nome: Raphael Leveque
* N Usp: 12542522
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 0

// Usando o mergeSort por ser mais rápido
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    int L[n1], R[n2];
  
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
  
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

int binarySearch(int arr[], int l, int r, int x, int *ans)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        if (arr[mid] == x){
			int j = mid;
			while (arr[j] == x)
			{
				(*ans)++;
				j--;
			}
			j = mid + 1;
			while (arr[j] == x)
			{
				(*ans)++;
				j++;			
			}
            return mid;
			
			
		}

  
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x, ans);
  
        return binarySearch(arr, mid + 1, r, x, ans);
    }
    return -1;
}

int search(int** arr, int n, int x)
{
    int i;
    for (i = 0; i < n; i++){
        if (arr[i][0] > x)
            return i - 1;
	}
	return i - 1;
}

unsigned int* search_and_count(int** matriz, int* vetor, int m, int z) {

	printf("Vetor z:\n");
    for(int i = 0; i < z; i++)
        printf("%d ", vetor[i]);
    printf("\n\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%.2d ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	
    
	int i, k, el;
	unsigned int* con = calloc(z, sizeof(unsigned int));
	for (k = 0; k < z; k++) {
	    el = vetor[k];
		int ans = 0;
		int linha = search(matriz, m, el);
		if(linha == -1) continue;
		i = linha;
		mergeSort(matriz[i], i + 1, m - 1);
		binarySearch(matriz[i], 0, m - 1, el, &ans);
		con[k] += ans;
	}
	return con;
}

int** alloc_matrix(int m) {
	int **mat = malloc(sizeof(int*)*m);
	srand(m);
	
	int in = 0;
	// aloca matriz ordenada
	for (int i = 0; i < m; i++) {
		mat[i] = malloc(sizeof(int)*m);
	    	for (int j = 0; j < m; j++) {
			if (i == j) in+= (rand()%3)+1;
			else in += rand()%3;
			mat[i][j] = in;
		}
	}
	// desordena matriz triangular superior
	for (int i = 0; i < m-2; i++) {
	    	for (int j = i+1; j < m-1; j++) {
			int swaps = (int)((m-j)/2.0)+1;
			for (int t = 1; t <= swaps; t++) {
				int a = (rand()%(m-j))+j;
				int b = (rand()%(m-j))+j;
				int tmp = mat[i][a];
				mat[i][a] = mat[i][b];
				mat[i][b] = tmp;
			}
		}

	}
	return mat;
}

int* alloc_vec(int z) {
	int *vet = malloc(sizeof(int)*z);
	srand(z);
	vet[0] = rand()%2;
	for (int i = 1; i < z; i++) {
		vet[i] = vet[i-1]+(rand()%9)+1;
	}
	return vet;
}


int main (int argc, char* argv[]) {

	int m;
	int z;
	scanf("%d", &m);
	scanf("%d", &z);

	int** mat = alloc_matrix(m);
	int* vet = alloc_vec(z);


	unsigned int* c = search_and_count(mat, vet, m, z);

	for (int i = 0; i < z; i++) printf("%hu ", c[i]);
	printf("\n");

	for (int i = 0; i < m; i++) free(mat[i]);
	free(mat);
	free(vet);

	return 0;
}

