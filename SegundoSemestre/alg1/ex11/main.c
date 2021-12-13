#include "arvore.h"

int main() {
    string_t operacao = malloc(15 * sizeof(char));
    string_t ordem = malloc(15 * sizeof(char));
    arvore_t *a = criar();

    while ((scanf("%14s", operacao)) != EOF) {
        if (strcmp(operacao, "impressao") == 0) {
            scanf("%s%*[\r\n]", ordem);
            if (esta_vazia(a)) {
                printf("VAZIA\n");
                continue;
            }

            if (strcmp(ordem, "pre-ordem") == 0) {
                pre_ordem(a->raiz);
                printf("\n");

            } else if (strcmp(ordem, "em-ordem") == 0) {
                em_ordem(a->raiz);
                printf("\n");

            } else if (strcmp(ordem, "pos-ordem") == 0) {
                pos_ordem(a->raiz);
                printf("\n");
            }
        } else if (strcmp(operacao, "insercao") == 0) {
            int num;
            scanf("%d ", &num);
            inserir(&a->raiz, num);
        }
    }

    finalizar(a->raiz);
    free(a);
    free(operacao);
    free(ordem);
    return 0;
}