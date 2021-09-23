#include "strings.h"

int main()
{
    string_t frase = malloc(101 * sizeof(char));
    string_t erro = malloc(21 * sizeof(char));
    string_t correcao = malloc(21 * sizeof(char));
    string_t *fraseCorrigida = malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++)
    {
        fraseCorrigida[i] = malloc(101 * sizeof(char));
    }
    

    for (int i = 0; i < 3; i++)
    {
        lendoString(frase);
        lendoString(erro);
        lendoString(correcao);
        strcpy(fraseCorrigida[i], frase);
        corrigindoString(frase, erro, correcao, fraseCorrigida[i]);
    }


    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", fraseCorrigida[i]);
        free(fraseCorrigida[i]);
    }
    free(fraseCorrigida);
    free(frase);
    free(erro);
    free(correcao);

    return 0;
}