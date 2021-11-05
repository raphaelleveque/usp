#include "lista.h"

int main() {
    list_t *l = create();
    char tmp;
    char operation[15];
    int id;
    char name[51];
    while ((tmp = getchar()) != EOF) {
        ungetc(tmp, stdin);
        scanf("%s", operation);
        if (!strcmp(operation, "INSERE")) {
            scanf("%d ", &id);
            scanf("%[^\r\n]%*c%*c", name);
            if (insert(l, id, name) == -1)
                printf("INVALIDO\n");
        } else if (!strcmp(operation, "REMOVE")) {
            scanf("%d%*c%*c", &id);
            if (removeId(l, id) == -1)
                printf("INVALIDO\n");
        } else if (!strcmp(operation, "IMPRIMIR")) {
            scanf("%*c%*c");
            print(l);
        }
    }

    return 0;
}