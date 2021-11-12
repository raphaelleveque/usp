#include "skiplist.h"
#include <time.h>

int main() {
    srand(time(NULL));
    Skiplist *sk = cria(10, 0.4);
    char c;
    while ((c = getchar()) != EOF) {
        ungetc(c, stdin);

        string operacao = malloc(15 * sizeof(char));
        string verbete = malloc(55 * sizeof(char));
        scanf("%s%*c", operacao);

        if (strcmp(operacao, "insercao") == 0) {
            string definicao = malloc(145 * sizeof(char));
            scanf("%s%*c", verbete);
            scanf("%[^\r\n]%*[\r\n]", definicao);
            insereSkipList(sk, verbete, definicao) ? 1 : printf("OPERACAO INVALIDA\n");
            ;
            free(definicao);

        } else if (strcmp(operacao, "alteracao") == 0) {
            string definicao = malloc(145 * sizeof(char));
            scanf("%s%*c", verbete);
            scanf("%[^\r\n]%*[\r\n]", definicao);
            alteracao(sk, verbete, definicao) ? 1 : printf("OPERACAO INVALIDA\n");
            free(definicao);

        } else if (strcmp(operacao, "remocao") == 0) {
            scanf("%s%*[\r\n]", verbete);
            removeSkiplist(sk, verbete) ? 1 : printf("OPERACAO INVALIDA\n");
            ;

        } else if (strcmp(operacao, "busca") == 0) {
            scanf("%s%*[\r\n]", verbete);
            node *def = buscaSkipList(sk, verbete);
            def == NULL ? printf("OPERACAO INVALIDA\n") : printf("%s %s\n", def->chave, def->definicao);

        } else if (strcmp(operacao, "impressao") == 0) {
            scanf("%s%*[\r\n]", verbete);
            imprimeLista(sk, verbete[0]);
        }

        free(operacao);
        free(verbete);
    }

    return 0;
}