#include "lista.h"

string_t lerLinha(FILE *std);
void lendoArquivo(FILE *arq, lista_t *l);
alfabeto_t *vetorIndices(lista_t *l, int *tamAlf, alfabeto_t *tmp);
void buscaVetor(lista_t *l, alfabeto_t *alf, string_t palavraAProcurar);


int main() {
    char codigo;
    string_t nomeArquivo = NULL;
    lista_t *l = cria();
    alfabeto_t *alf = NULL;
    int tamAlf = 0;
    int alfAtualizado = 0;

    while ((codigo = getchar()) != '0') {
        scanf("%*[\r\n]");
        if (codigo == '1') {
            nomeArquivo = lerLinha(stdin);
            FILE *arq = fopen(nomeArquivo, "r");
            lendoArquivo(arq, l);
            alfAtualizado = 0;
            free(nomeArquivo);

        } else if (codigo == '2') {
            tamAlf = 0;
            alf = vetorIndices(l, &tamAlf, alf);
            printf("%d\n", tamAlf);
            alfAtualizado = 1;
        } else {
            string_t palavraAProcurar = lerLinha(stdin);
            if (!alfAtualizado) {
                printf("Vetor de indices nao atualizado.\n");
                continue;
            }
            buscaVetor(l, alf, palavraAProcurar);
            free(palavraAProcurar);
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
    int i = 0;
    do {
        i = fscanf(std, "%c", &string[characters]);
        if (string[characters] == '\n' || i == EOF) {
            if (string[characters - 1] == '\r')
                characters--;

            string[characters] = '\0';
        }
        characters++;
        if (characters == numberMaxChar) {
            numberMaxChar *= 2;
            string = realloc(string, (numberMaxChar) * sizeof(char));
        }

    } while (string[characters - 1] != '\0' && i != EOF);

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

alfabeto_t *vetorIndices(lista_t *l, int *tamAlf, alfabeto_t *tmp) {
    if (tmp != NULL)
        free(tmp);
    alfabeto_t *alf = malloc(26 * sizeof(alfabeto_t));
    for (int i = 0; i < 26; i++)
        alf[i].no = NULL;

    no_t *p = l->inicio;
    while (p != NULL) {
        int c = p->info[0] - 'a';
        if (alf[c].no == NULL) {
            alf[c].no = p;
            (*tamAlf)++;
        }
        p = p->prox;
    }
    return alf;
}

void buscaVetor(lista_t *l, alfabeto_t *alf, string_t palavraAProcurar) {
    int nosPercorridos = 0;
    int c = palavraAProcurar[0] - 'a';
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