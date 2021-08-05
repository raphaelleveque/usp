#include <stdio.h>
#include <stdbool.h>

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


    if (jogo_da_velha[0][0] == 'x' && jogo_da_velha[1][1] == 'x' && jogo_da_velha[2][2] == 'x')
    {
        printf("x ganhou\n");
        return 0;        
    }
    else if (jogo_da_velha[0][2] == 'x' && jogo_da_velha[1][1] == 'x' && jogo_da_velha[2][0] == 'x')
    {
        printf("x ganhou\n");        
        return 0;        
    }
    else if (jogo_da_velha[0][0] == 'o' && jogo_da_velha[1][1] == 'o' && jogo_da_velha[2][2] == 'o')
    {
        printf("o ganhou\n");        
        return 0;        
    }
    else if (jogo_da_velha[0][2] == 'o' && jogo_da_velha[1][1] == 'o' && jogo_da_velha[2][0] == 'o')
    {
        printf("o ganhou\n");         
        return 0;        
    }
   

    for (int i = 0; i < 3; i++)
    {
        int contadorX = 0, contadorO = 0;
        for (int j = 0; j < 3; j++)
        {
            if (jogo_da_velha[i][j] == 'x')
            {
                contadorX++;
            }
            else if (jogo_da_velha[i][j] == 'o')
            {
                contadorO++;
            }
            if (contadorX == 3)
            {
                printf("x ganhou\n");
                return 0;
            }
            else if (contadorO == 3)
            {
                printf("o ganhou\n");
                return 0;
            }           
        }
        contadorX = 0, contadorO = 0;
        for (int j = 0; j < 3; j++)
        {
            if (jogo_da_velha[j][i] == 'x')
            {
                contadorX++;
            }
            else if (jogo_da_velha[j][i] == 'o')
            {
                contadorO++;
            }
            if (contadorX == 3)
            {
                printf("x ganhou\n");
                return 0;
            }
            else if (contadorO == 3)
            {
                printf("o ganhou\n");
                return 0;
            }           
        }        
    }
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