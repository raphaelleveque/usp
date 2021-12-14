#include "treap.h"
typedef char* string_t;


int main() {
    string_t operacao = malloc(15 * sizeof(char));
    string_t ordem = malloc(15 * sizeof(char));
    treapNode_t *raiz = NULL;

    int n;
    scanf("%d ", &n);

    for (int i = 0; i < n; i++) {
        scanf("%14s", operacao);
        if (strcmp(operacao, "impressao") == 0) {
            scanf("%s%*[\r\n]", ordem);
            if (raiz == NULL) {
                printf("VAZIA\n");
                continue;
            }
            if (strcmp(ordem, "preordem") == 0) {
                pre_ordem(raiz);
                printf("\n");

            } else if (strcmp(ordem, "ordem") == 0) {
                em_ordem(raiz);
                printf("\n");

            } else if (strcmp(ordem, "posordem") == 0) {
                pos_ordem(raiz);
                printf("\n");

            } else if (strcmp(ordem, "largura") == 0) {
                printLevelOrder(raiz);
                printf("\n");
            }


        } else if (strcmp(operacao, "insercao") == 0) {
            int chave, prioridade;
            scanf("%d %d ", &chave, &prioridade);
            if (search(raiz, chave) != NULL)
                printf("Elemento ja existente\n");
            else
                raiz = insert(raiz, chave, prioridade);


        } else if (strcmp(operacao, "remocao") == 0) {
            int chave;
            scanf("%d ", &chave);
            if (search(raiz, chave) == NULL)
                printf("Chave nao localizada\n");
            else
                raiz = deleteNode(raiz, chave);


        } else if (strcmp(operacao, "buscar") == 0) {
            int chave;
            scanf("%d ", &chave);
            if (search(raiz, chave) == NULL)
                printf("0\n");
            else
                printf("1\n");
        }
    }

    finalizar(raiz);
    free(operacao);
    free(ordem);
    return 0;
}