// Raphael Leveque 12542522
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *lerLinha(int *caracteres);
bool palindromoOuNao(int caracteres, char *frase, bool *palindromoDireto);

int main()
{
    int caracteres = 0;
    char *frase = lerLinha(&caracteres);

    bool palindromo, palindromoDireto = true;
    palindromo = palindromoOuNao(caracteres, frase, &palindromoDireto);

    if (!palindromo)
    {
        printf("Nao eh um palindromo\n");
    }
    else if (palindromoDireto)
    {
        printf("Palindromo direto\n");
    }
    else
    {
        printf("Palindromo indireto\n");
    }
    free(frase);

    return 0;
}

// Lê o conteúdo da Linha e ignora os caracteres especiais, com excessão de alguns
char *lerLinha(int *caracteres)
{
    scanf("%*[\n\r]s");
    char *frase = malloc(sizeof(char));
    int nmrMaxChar = 1;
    do
    {
        scanf("%c", &frase[*caracteres]);
        frase[*caracteres] = tolower(frase[*caracteres]);

        bool caracteresEspeciais = (frase[*caracteres] == '/' || frase[*caracteres] == ' ' || frase[*caracteres] == '\n');

        if (!(isalnum(frase[*caracteres]) || caracteresEspeciais))
        {
            continue;
        }

        if (frase[*caracteres] == '\n' || frase[*caracteres] == EOF)
        {
            frase[*caracteres] = '\0';
        }
        (*caracteres)++;
        if (*caracteres == nmrMaxChar)
        {
            nmrMaxChar *= 2;
            frase = realloc(frase, (nmrMaxChar) * sizeof(char));
        }

    } while (frase[*caracteres - 1] != '\0');

    frase = realloc(frase, (*caracteres) * sizeof(char));
    (*caracteres)--;

    return frase;
}

bool palindromoOuNao(int caracteres, char *frase, bool *palindromoDireto)
{
    if (strlen(frase) == 1 || strlen(frase) == 0)
    {
        return true;
    }

    // Verifica se é palíndromo direto ou indireto
    if (!(isalnum(frase[0])) || !(isalnum(frase[caracteres - 1])))
    {
        *palindromoDireto = (frase[0] == frase[caracteres - 1]);
        if (!(*palindromoDireto))
        {
            caracteres--;
            if (isalnum(frase[0]))
            {
                frase[caracteres] = '\0';
            }
            else
            {
                frase[0] = '\0';
                frase++;
            }
        }
    }

    if (frase[0] != frase[caracteres - 1])
    {
        return false;
    }
    else
    {
        frase[0] = '\0';
        frase[caracteres - 1] = '\0';
        frase++;
        caracteres -= 2;
        return palindromoOuNao(caracteres, frase, palindromoDireto);
    }
}