#include "primos.h"

int main()
{
    int quantidadePrimos;
    scanf("%d", &quantidadePrimos);
    indices_t indices = malloc(quantidadePrimos * sizeof(int));

    int maiorIndice = lendoNumeros(quantidadePrimos, indices);

    primos_t primos = malloc((maiorIndice + 1) * sizeof(int));
    encontrePrimos(primos, maiorIndice);

    for (int j = 0; j < quantidadePrimos; j++)
    {
        printf("%d ", primos[indices[j]]);
    }

    free(primos);
    free(indices);

    return 0;
}