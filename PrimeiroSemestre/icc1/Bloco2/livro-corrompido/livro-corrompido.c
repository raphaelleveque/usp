#include <stdio.h>
#include <stdlib.h>

char * read_line()
{
    char *frase = malloc(sizeof(char));
    int caracteres = 0;
    int nmr_max_char = 1;
    do
    {
        scanf("%c", &frase[caracteres]);
        if (frase[caracteres] == '\n' || frase[caracteres] == EOF)
        {
            frase[caracteres] = '\0';
        }
        caracteres++;
        if (caracteres == nmr_max_char)
        {
            nmr_max_char *= 2;
            frase = realloc(frase, (nmr_max_char) * sizeof(char));
        }

    }while (frase[caracteres-1] != '\0');

    frase = realloc(frase, (caracteres + 1) * sizeof(char));
    
    return frase;
}

int main()
{
    int numero_linhas;
    scanf("%d", &numero_linhas);
    scanf("%*[\r\n]s");
    char **frase = malloc(numero_linhas * sizeof(char*));

    for (int i = 0; i < numero_linhas; i++)
    {
        *(frase + i) = read_line();
    }
    

    int nmr_linhas_validas;
    scanf("%d", &nmr_linhas_validas);
    if (nmr_linhas_validas == 0)
    {
        return 0;
    }
    

    int linhas_validas[nmr_linhas_validas];
    for (int i = 0; i < nmr_linhas_validas; i++)
    {
        scanf("%d", &linhas_validas[i]);
        printf("%s\n", frase[linhas_validas[i]]);
    }
    

    for(int i = 0; i < numero_linhas; i++)
	{
        free(frase[i]); 
    }
    free(frase);  


    return 0;
}