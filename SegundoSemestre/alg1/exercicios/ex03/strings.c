#include "strings.h"

void lendoString(string_t string)
{
    scanf("%*[\n]s");
    
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' )
    {
        string[i] = c;
        i++;
    }
    string[i] = '\0';
}


void corrigindoString(string_t frase, string_t erro, string_t correcao, string_t fraseCorrigida)
{
    int palavraErrada = 0;
    for (int i = 0; i < strlen(fraseCorrigida); i++)
    {
        if (fraseCorrigida[i] == erro[0])
        {
            int j;
            for (j = 0; j < strlen(erro); j++)
            {
                palavraErrada = (frase[i + j] == erro[j]) ? 1 : 0;
            }
            if (palavraErrada)
            {
                palavraErrada = 0;
                string_t substring1 = malloc((i + 1) * sizeof(char));
                substring1[i] = '\0';
                strncpy(substring1, fraseCorrigida, i);

                string_t substring2 = malloc((strlen(frase) - i) * sizeof(char));
                strcpy(substring2, &fraseCorrigida[i + strlen(erro)]);

                strcpy(fraseCorrigida, "");

                strcat(fraseCorrigida, substring1);
                strcat(fraseCorrigida, correcao);
                strcat(fraseCorrigida, substring2);

                free(substring1);
                free(substring2);
            }
            
        }
        
    }   
}