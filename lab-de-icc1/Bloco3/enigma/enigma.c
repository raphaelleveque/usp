#include <stdio.h>

void giro_rotor(int i, int rotores[3][26])
{
    int troca = rotores[i][0];
    for (int k = 0; k < 25; k++)
    {
        rotores[i][k] = rotores[i][k+1];
    }
    rotores[i][25] = troca;
}

int main()
{
    int rotores[3][26];

    scanf("%*[^\r\n]s");
    scanf("%*[\r\n]s");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            scanf("%d", &rotores[i][j]);
        }
    }
    
	scanf("%*[^\r\n]s");
    scanf("%*[\r\n]s");
    scanf("%*[^\r\n]s");
    scanf("%*[\r\n]s");

    char texto_codificado;
    int primeiro_giro = 0, segundo_giro = 0;
    while ((texto_codificado = getchar()) != EOF)
    {
        if (primeiro_giro == 26)
        {
            segundo_giro++;
            primeiro_giro = 0;
            giro_rotor(1, rotores);
        }
        if (segundo_giro == 26)
        {
            segundo_giro = 0;
            giro_rotor(2, rotores);
        }
        
        int texto_descodificado;
        if (texto_codificado >= 'A' && texto_codificado <= 'Z')
        {
            texto_descodificado = rotores[0][texto_codificado  - 65];
            texto_descodificado = rotores[1][texto_descodificado];
            texto_descodificado = rotores[2][texto_descodificado];
            printf("%c", texto_descodificado + 65);

            giro_rotor(0, rotores);
            primeiro_giro++;
        }
        else if (texto_codificado >= 'a' && texto_codificado <= 'z')
        {
            texto_descodificado = rotores[0][texto_codificado  - 97];
            texto_descodificado = rotores[1][texto_descodificado];
            texto_descodificado = rotores[2][texto_descodificado];
            printf("%c", texto_descodificado + 97);

            giro_rotor(0, rotores);
            primeiro_giro++;
        }
        else
        {
			printf("%c", texto_codificado);
        }
    }

    return 0;
}