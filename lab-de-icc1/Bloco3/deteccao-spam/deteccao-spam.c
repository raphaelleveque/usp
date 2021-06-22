#include <stdio.h>
#include <string.h>

void limpando_vetor(char caractere[9])
{
    for (int i = 0; i < 9; i++)
    {
        caractere[i] = 0;
    }
}

int main()
{
    char caractere[9] = {};
    int i = 0, spam = 0, contador_caractere = 0, limite_caracteres = 0;;

    scanf("%*[^\r\n]s"); // Ignora tudo até o final da linha
    scanf("%*[\r\n]s"); // Ignora o pula linha  
    while ((caractere[i] = getchar()) != EOF)
    {
        if (contador_caractere > 76)
        {
            limite_caracteres = 1;
            return 0;
        }
        

        if (!((caractere[i] >= 'a' && caractere[i] <= 'z') || (caractere[i] >= 'A' && caractere[i] <= 'Z')))
        {
            i = 0;
            contador_caractere++;
            limpando_vetor(caractere);
            continue;
        }
        

        if (!strcmp(caractere, "gratuito"))
        {
            spam++;
            i = 0;
            limpando_vetor(caractere);
            continue;
        }
        else if (!strcmp(caractere, "atencao"))
        {
            spam++;
            i = 0;
            limpando_vetor(caractere);
            continue;
        }
        else if (!strcmp(caractere, "urgente"))
        {
            spam++;
            i = 0;
            limpando_vetor(caractere);
            continue;
        }
        else if (!strcmp(caractere, "imediato"))
        {
            spam++;
            i = 0;
            limpando_vetor(caractere);
            continue;
        }
        else if (!strcmp(caractere, "zoombie"))
        {
            spam++;
            i = 0;
            limpando_vetor(caractere);
            continue;
        }
        else if (!strcmp(caractere, "oferta"))
        {
            spam++;
            i = 0;
            limpando_vetor(caractere);
            continue;
        }
        else if (!strcmp(caractere, "dinheiro"))
        {
            spam++;
            i = 0;
            limpando_vetor(caractere);
            continue;
        }
        else if (!strcmp(caractere, "renda"))
        {
            spam++;
            i = 0;
            limpando_vetor(caractere);
            continue;            
        }
        else if (!strcmp(caractere, "fundo"))
        {
            spam++;
            i = 0;
            limpando_vetor(caractere);
            continue;            
        }
        else if (!strcmp(caractere, "limitado"))
        {
            spam++;
            i = 0;
            limpando_vetor(caractere);
            continue;            
        }
        else if (!strcmp(caractere, "ajuda"))
        {
            spam++;
            i = 0;
            limpando_vetor(caractere);
            continue;            
        }
        else if (!strcmp(caractere, "SOS"))
        {
            spam++;
            i = 0;
            limpando_vetor(caractere);
            continue;            
        }   

        if(caractere[i] != '\n')
        {
            contador_caractere++;
        }
        else
        {
            contador_caractere = 0;
        }
        
        i++;
        if (i == 9)
        {
            i = 0;
        }
        
    }
    if (spam >= 2)
    {
        printf("Spam\n");
        return 0;
    }
    else if (limite_caracteres)
    {
        printf("Spam\n");
        return 0;
    }
    
    else
    {
        printf("Inbox\n");
        return 0;
    }

    return 0;
}