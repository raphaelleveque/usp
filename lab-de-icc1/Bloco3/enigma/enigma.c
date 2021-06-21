#include <stdio.h>
#include <stdbool.h>

enum rotores 
{
    Rotor0,
    Rotor1, 
    Rotor2
};

int main()
{
    int rotores[3][26];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            scanf("%d", &rotores[i][j]);
        }
    }

    char texto_codificado;
    int i = 0, j = 0;
    while ((texto_codificado = getchar()) != EOF)
    {
        if (j == 26)
        {
            i++;
            j = 0;
        }
        char texto_descodificado;
        if (texto_codificado >= 'A' && texto_codificado <= 'Z')
        {
            texto_descodificado = rotores[Rotor0][texto_codificado  - 65];
            texto_descodificado = rotores[Rotor1][texto_descodificado];
            texto_descodificado = rotores[Rotor2][texto_descodificado];
            printf("%c", texto_descodificado + 65);
        }
        else if (texto_codificado >= 'a' && texto_codificado <= 'z')
        {
            texto_descodificado = rotores[Rotor0][texto_codificado  - 97];
            texto_descodificado = rotores[Rotor1][texto_descodificado];
            texto_descodificado = rotores[Rotor2][texto_descodificado];
            printf("%c", texto_descodificado + 97);
        }
        else
        {
            printf("%c", texto_codificado);
        }

        int troca = rotores[i][0];
        for (int k = 0; k < 25; k++)
        {
            rotores[i][k] = rotores[i][k+1];
        }
        rotores[i][25] = troca;
        j++;
    }
    

    return 0;
}