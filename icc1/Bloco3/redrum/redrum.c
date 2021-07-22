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

    bool palindromoSimOuNao, palindromoDireto = false;
    char *fraseDeVerificacao = malloc((caracteres + 1) * sizeof(char));    
    strcpy(fraseDeVerificacao, frase);
    palindromoSimOuNao = palindromoOuNao(caracteres, fraseDeVerificacao, &palindromoDireto);

    if (!palindromoSimOuNao)
    {
        printf("Nao eh um palindromo\n");
        return 0;
    }
    else if (palindromoDireto)
    {
        printf("Palindromo Direto\n");
    }
    else
    {
        printf("Palindromo Indireto\n");
    }
    
    return 0;
}

char *lerLinha(int *caracteres)
{
    scanf("%*[\n\r]s");
    char *frase = malloc(sizeof(char));
    int nmrMaxChar = 1;
    do
    {
        scanf("%c", &frase[*caracteres]);

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

    frase = realloc(frase, (*caracteres + 1) * sizeof(char));

    return frase;
}


bool palindromoOuNao(int caracteres, char *frase, bool *palindromoDireto)
{
    if (strlen(frase) == 1 || strlen(frase) == 0)
    {
        return true;
    }

    if(!(isalnum(frase[0]) || isalnum(frase[caracteres - 1])))
    {
        *palindromoDireto = (frase[0] == frase[caracteres - 1]);
        if (!(*palindromoDireto))
        {
            caracteres = isalnum(frase[0]) ? caracteres : caracteres + 1;
            caracteres = isalnum(frase[caracteres - 1]) ? caracteres : caracteres - 1;
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