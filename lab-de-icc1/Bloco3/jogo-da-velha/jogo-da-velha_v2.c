#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void verificacao_em_linha(int i, int j, char jogo_da_velha[3][3], int *contadorX, int *contadorO);
void verificacao_diagonal(char jogo_da_velha[3][3], char caractere);

void verificacao_em_linha(int i, int j, char jogo_da_velha[3][3], int *contadorX, int *contadorO)
{    
    if (jogo_da_velha[i][j] == 'x')
    {
        *contadorX = *contadorX + 1;
    }
    else if (jogo_da_velha[i][j] == 'o')
    {
        *contadorO = *contadorO + 1;
    }
    if (*contadorX == 3)
    {
        printf("x ganhou\n");
        exit(0);
    }
    else if (*contadorO == 3)
    {
        printf("o ganhou\n");
        exit(0);
    }           
}

void verificacao_diagonal(char jogo_da_velha[3][3], char caractere)
{
    if (jogo_da_velha[0][0] == caractere && jogo_da_velha[1][1] == caractere && jogo_da_velha[2][2] == caractere)
    {
        printf("%c ganhou\n", caractere);
        exit(0);        
    }
    else if (jogo_da_velha[0][2] == caractere && jogo_da_velha[1][1] == caractere && jogo_da_velha[2][0] == caractere)
    {
        printf("%c ganhou\n", caractere);        
        exit(0);        
    }
}


int main()
{
    char jogo_da_velha[3][3];
    bool partida_em_jogo = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf(" %c", &jogo_da_velha[i][j]);
            if (jogo_da_velha[i][j] == '-')
            {
                partida_em_jogo = true;
            }
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        int contador1X = 0, contador1O = 0;
        int contador2X = 0, contador2O = 0;
        for (int j = 0; j < 3; j++)
        {
            verificacao_em_linha(i, j, jogo_da_velha, &contador1X, &contador1O);
            verificacao_em_linha(j, i, jogo_da_velha, &contador2X, &contador2O);    
        }   
    }
    verificacao_diagonal(jogo_da_velha, 'x');
    verificacao_diagonal(jogo_da_velha, 'o');

    if (partida_em_jogo == true)
    {
        printf("em jogo\n");
    }
    else
    {
    printf("empate\n");
    }    

    return 0;
}
