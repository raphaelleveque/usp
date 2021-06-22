#include <stdio.h>
#include <string.h>

int main()
{
    char caractere[9], teste;
    int i = 0, spam = 0, contador_caractere = 0;
    while ((caractere[i] = getchar()) != EOF)
    {
        if (!(caractere[i] >= 'a' && caractere[i] <= 'z'))
        {
            i = 0;
            continue;
        }
        

        if (!strcmp(caractere, "gratuito"))
        {
            spam++;
        }
        else if (strcmp(caractere, "atencao"))
        {
            spam++;
        }
        else if (strcmp(caractere, "urgente"))
        {
            spam++;
        }
        else if (strcmp(caractere, "imediato"))
        {
            spam++;
        }
        else if (strcmp(caractere, "zoombie"))
        {
            spam++;
        }
        else if (strcmp(caractere, "oferta"))
        {
            spam++;
        }
        else if (strcmp(caractere, "dinheiro"))
        {
            spam++;
        }
        else if (strcmp(caractere, "renda"))
        {
            spam++;
        }
        else if (strcmp(caractere, "fundo"))
        {
            spam++;
        }
        else if (strcmp(caractere, "limitado"))
        {
            spam++;
        }
        else if (strcmp(caractere, "ajuda"))
        {
            spam++;
        }
        else if (strcmp(caractere, "SOS"))
        {
            spam++;
        }

        while (caractere[i] != '\n')
        {
            contador_caractere++;
        }
        

        i++;
    }
    

    return 0;
}