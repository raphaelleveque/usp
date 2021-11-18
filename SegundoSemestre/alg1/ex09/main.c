#include "lista.h"

void lerNumero(lista_t *num) {
    char algChar;
    elem algarismo;
    while ((algChar = getchar()) != ' ' && algChar != '\r' && algChar != '\n') {
        if (algChar == '-') {
            insere(num, -1);
            num->tam--;
            continue;
        }
        algarismo = algChar - '0';
        insere(num, algarismo);
    }
}

int main() {
    int nLinhas;
    scanf("%d%*[\r\n]", &nLinhas);
    char *operacao = malloc(4 * sizeof(char));

    for (int i = 0; i < nLinhas; i++) {
        scanf("%s%*c", operacao);
        lista_t *num1 = cria();
        lerNumero(num1);
        lista_t *num2 = cria();
        lerNumero(num2);

        if (strcmp(operacao, "SUM") == 0) {
            if (num1->ini->info == -1 || num2->ini->info == -1)
                preDiferenca(num1, num2);
            else
                preSoma(num1, num2);

        } else if (strcmp(operacao, "BIG") == 0) {
            int maior = maiorOuMenor(num1, num2);
            if (maior == 1)
                printf("1\n");
            else
                printf("0\n");

        } else if (strcmp(operacao, "SML") == 0) {
            int menor = maiorOuMenor(num1, num2);
            if (menor == -1)
                printf("1\n");
            else
                printf("0\n");

        } else if (strcmp(operacao, "EQL") == 0) {
            int igual = maiorOuMenor(num1, num2);
            if (igual == 0)
                printf("1\n");
            else
                printf("0\n");
        }

        liberar(num1);
        liberar(num2);
    }
    fflush(stdin);
    return 0;
}