#include "arvore.h"

int main() {
    int nos;
    scanf("%d", &nos);
    
    arvore_t *a = cria();
    for (int i = 0; i < nos; i++) {
        no_t tmp;
        scanf("%d %d %d %d", &tmp.id, &tmp.info, &tmp.idEsq, &tmp.idDir);
        no_t *pai = busca_pai(a->raiz, tmp.id);

        if (pai == NULL) {
            inserir_esq(a, tmp, NULL);
        } else if (pai->idEsq == tmp.id) {
            inserir_esq(a, tmp, pai);
        } else if (pai->idDir == tmp.id) {
            inserir_dir(a, tmp, pai);
        }
    }
    int sum = soma(a->raiz);
    if (sum != -1)
        printf("VERDADEIRO\n");
    else 
        printf("FALSO\n");

    finalizar(a->raiz);
    return 0;
}