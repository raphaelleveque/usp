#include "lista.h"

lista_t *cria() {
    lista_t *l = malloc(sizeof(lista_t));
    l->ini = NULL;
    l->fim = NULL;
    l->tam = 0;
    return l;
}

void liberar(lista_t *l) {
    if (l == NULL)
        return;

    node *p = l->ini;
    while (p != NULL) {
        l->ini = p->prox;
        free(p);
        p = l->ini;
    }
    free(l);
}

void insere(lista_t *l, elem x) {
    node *p = malloc(sizeof(node));
    p->info = x;
    p->prox = NULL;
    p->anterior = l->fim;

    if (l->ini == NULL) {
        l->ini = p;
    } else {
        l->fim->prox = p;
    }
    l->fim = p;
    l->tam++;
}

void preSoma(lista_t *num1, lista_t *num2) {
    if (num1->tam >= num2->tam)
        soma(num1, num2);
    else
        soma(num2, num1);
}

void soma(lista_t *num1, lista_t *num2) {
    lista_t *res = cria();
    node *p1 = num1->fim;
    node *p2 = num2->fim;
    elem resSoma, resto = 0;

    while (p2 != NULL) {

        resSoma = p1->info + p2->info + resto;
        resto = (resSoma - (resSoma % 10)) / 10.0;
        insere(res, resSoma % 10);
        p1 = p1->anterior;
        p2 = p2->anterior;
    }
    while (p1 != NULL) {
        resSoma = p1->info + resto;
        resto = (resSoma - (resSoma % 10)) / 10.0;
        insere(res, resSoma % 10);
        p1 = p1->anterior;
    }
    resto = (resSoma - (resSoma % 10)) / 10.0;
    resto == 0 ? 1 : insere(res, resto);
    imprimeLista(res);
    liberar(res);
}

void preDiferenca(lista_t *num1, lista_t *num2) {
    if (num1->tam > num2->tam) {
        if (num1->ini->info == -1)
            diferenca(num1, num2, -1);
        else
            diferenca(num1, num2, 1);
    } else if (num1->tam < num2->tam) {
        if (num2->ini->info == -1)
            diferenca(num2, num1, -1);
        else
            diferenca(num2, num1, 1);
    } else {
        if (num1->ini->info != -1)
            diferenca(num1, num2, 0);
        else
            diferenca(num2, num1, 0);
    }
}

void diferenca(lista_t *num1, lista_t *num2, int sinal) {
    lista_t *res = cria();
    node *p1 = num1->fim;
    node *p2 = num2->fim;
    elem resDiferenca;
    int negativo = 0;
    while (p2 != NULL && p2->info != -1) {
        if (p1->info > p2->info) {
            resDiferenca = p1->info - p2->info;
        } else {
            node *tmp = p1->anterior;
            while (tmp != NULL && tmp->info == 0) {
                tmp = tmp->anterior;
            }
            if (tmp == NULL) {
                resDiferenca = (p2->info - p1->info);
                negativo = 1;
            } else {
                tmp->info--;
                p1->info += 10;
                resDiferenca = p1->info - p2->info;
            }
        }
        insere(res, resDiferenca);
        p1 = p1->anterior;
        p2 = p2->anterior;
    }
    while (p1 != NULL && p1->info != -1 && p1->info != 0) {
        insere(res, p1->info);
        p1 = p1->anterior;
    }
    sinal == -1 ? insere(res, -1) : 0;
    if (sinal == 0 && negativo == 1) {
        insere(res, -1);
    }
    imprimeLista(res);
    liberar(res);
}

void imprimeLista(lista_t *l) {
    node *p = l->fim;
    if (p->info == -1) {
        printf("-");
        p = p->anterior;
    }
    while (p->info == 0) 
        p = p->anterior;

    while (p != NULL) {
        printf("%d", p->info);
        p = p->anterior;
    }
    printf("\n");
}

int maiorOuMenor(lista_t *num1, lista_t *num2) {
    int num1Sinal = (num1->ini->info == -1) ? -1 : 1;
    int num2Sinal = (num2->ini->info == -1) ? -1 : 1;

    if (num1Sinal != num2Sinal) {
        if (num1Sinal == -1) return -1;
        return 1;
    }

    if (num1->tam > num2->tam) {
        return 1 * num1Sinal;
    }
    if (num1->tam < num2->tam) {
        return -1 * num1Sinal;
    }

    node *p1, *p2;
    p1 = num1Sinal == -1 ? num1->ini->prox : num1->ini;
    p2 = num2Sinal == -1 ? num2->ini->prox : num2->ini;

    while (p1 != NULL) {
        if (p1->info > p2->info)
            return 1 * num1Sinal;
        else if (p1->info < p2->info)
            return -1 * num1Sinal;
        p1 = p1->prox;
        p2 = p2->prox;
    }
    return 0;
}