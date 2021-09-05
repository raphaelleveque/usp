#include "conjuntos.h"

int main()
{
    conjuntos_t conjuntos;
    srand(time(NULL));

    criar_conjunto(conjuntos.conjuntoA);
    criar_conjunto(conjuntos.conjuntoB);

    interseccao(&conjuntos);
    uniao(&conjuntos);
    diferenca(&conjuntos, 'a');
    

    printf("A: ");
    imprime_conjunto(conjuntos.conjuntoA);
    printf("B: ");
    imprime_conjunto(conjuntos.conjuntoB);
    printf("Uniao: ");
    imprime_conjunto(conjuntos.uniao);
    printf("Interseccao: ");
    imprime_conjunto(conjuntos.interseccao);
    printf("Diferença A - B: ");
    imprime_conjunto(conjuntos.diferenca);


    return 0;
}

/*
array:    [0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1]
índice:    0  1  2  3  4  5  6  7  8  9  10

conjunto:  {2, 5, 8, 9, 10}
*/