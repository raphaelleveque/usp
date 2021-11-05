#include "polinomio.h"

int main() {
    int casos;
    scanf("%d", &casos);

    for (int i = 0; i < casos; i++) {
        lista_t *polinomio1 = cria();
        int nPolinomios;
        scanf("%d ", &nPolinomios);
        lendoPolinomio(polinomio1);

        for (int j = 1; j < nPolinomios; j++) {
            lista_t *polinomio2 = cria();
            lendoPolinomio(polinomio2);
            adicionandoPolinomios(polinomio1, polinomio2);
            liberar(polinomio2);
        }
        imprimir(polinomio1);
    }
}