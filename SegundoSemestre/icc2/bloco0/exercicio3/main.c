#include "lista.h"

string_t lerLinha(FILE *std);
void lendoArquivo(FILE *arq, lista_t *l);
alfabeto_t *vetorIndices(lista_t *l, int *tamAlf);
void buscaVetor(lista_t *l, alfabeto_t alf[26], string_t palavraAProcurar);

int main() {
    char codigo;
    string_t nomeArquivo;
    lista_t *l = cria();
    alfabeto_t *alf = NULL;
    int tamAlf = 0;
    int alfAtualizado = 0;
    int primeiro = 0;

    while ((codigo = getchar()) != '0') {
        scanf("%*[\r\n]");
        if (codigo == '1') {
            nomeArquivo = lerLinha(stdin);
            FILE *arq = fopen(nomeArquivo, "r");
            lendoArquivo(arq, l);
            alfAtualizado = 0;
            if (primeiro) {
                alfabeto_t *tmp = alf;
                free(tmp);
                alf = vetorIndices(l, &tamAlf);
                if (alf == NULL)
                    printf("\n\nEH NULO\n\n");
            }
            primeiro = 1;

        } else if (codigo == '2') {
            tamAlf = 0;
            alf = vetorIndices(l, &tamAlf);
            if (alf == NULL)
            printf("\n\nEH NULO\n\n");
            printf("%d\n", tamAlf);
            alfAtualizado = 1;
        } else {
            string_t palavraAProcurar = lerLinha(stdin);
            if (!alfAtualizado) {
                printf("Vetor de indices nao atualizado.\n");
                continue;
            }
            buscaVetor(l, alf, palavraAProcurar);
        }
    }
    liberar(l);
    free(alf);

    return 0;
}


string_t lerLinha(FILE *std) {
    fscanf(std, "%*[\n\r]s");
    string_t string = malloc(sizeof(char));
    int characters = 0;
    int numberMaxChar = 1;
    do {
        fscanf(std, "%c", &string[characters]);
        if (string[characters] == '\n' || string[characters] == EOF) {
            if (string[characters - 1] == '\r')
                characters--;
            string[characters] = '\0';
        }
        characters++;
        if (characters == numberMaxChar) {
            numberMaxChar *= 2;
            string = realloc(string, (numberMaxChar) * sizeof(char));
        }

    } while (string[characters - 1] != '\0');

    string = realloc(string, (characters + 1) * sizeof(char));

    return string;
}


void lendoArquivo(FILE *arq, lista_t *l) {
    while (!feof(arq)) {
        string_t palavra = lerLinha(arq);
        insere(l, palavra);
    }
    no_t *p = l->inicio;
    for (int i = 0; i < 3; i++) {
        printf("%s\n", p->info);
        p = p->prox;
    }
    fclose(arq);
}

alfabeto_t *vetorIndices(lista_t *l, int *tamAlf) {
    alfabeto_t *alf = malloc(26 * sizeof(alfabeto_t));
    no_t *p = l->inicio;
    while (p != NULL) {
        char c = p->info[0] - 97;
        if (alf[c].no == NULL) {
            alf[c].no = p;
            (*tamAlf)++;
        }
        p = p->prox;
    }
    return alf;
}

void buscaVetor(lista_t *l, alfabeto_t alf[26], string_t palavraAProcurar) {
    int nosPercorridos = 0;
    int c = palavraAProcurar[0] - 97;
    no_t *p = alf[c].no;

    while (p != NULL && p->info[0] == palavraAProcurar[0]) {
        if (strcmp(p->info, palavraAProcurar) == 0) {
            printf("%d\n", nosPercorridos);
            return;
        }
        p = p->prox;
        nosPercorridos++;
    }
    printf("Palavra nao existe na lista.\n");
}