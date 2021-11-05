#include "polinomio.h"

void lendoPolinomio(lista_t *polinomio) {
    char c;
    while ((c = getchar()) != ')') {
        if (c != '(' && c != ',' && c != '\r' && c != '\n') {
            ungetc(c, stdin);
            int tmpNum;
            scanf("%d ", &tmpNum);
            insere(polinomio, tmpNum);
        }
    }
}

void adicionandoPolinomios(lista_t *polinomio1, lista_t *polinomio2) {
    node *p1 = polinomio1->ini;
    node *p2 = polinomio2->ini;
    while (p1 != NULL && p2 != NULL) {
        p1->info = p1->info + p2->info;
        p1 = p1->prox;
        p2 = p2->prox;
    }
    if (polinomio1->tam < polinomio2->tam) {
        while (p2 != NULL) {
            insere(polinomio1, p2->info);
            p2 = p2->prox;
        }
    }
}

void imprimir(lista_t *l) {
    printf("(");
    node *p = l->ini;
    while (p->prox != NULL) {
        printf("%d,", p->info);
        p = p->prox;
    }
    printf("%d", p->info);
    printf(")\n");
}