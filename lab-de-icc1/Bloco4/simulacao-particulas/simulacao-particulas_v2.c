#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

#define AMARELO "\033[0;33m"
#define VERMELHO "\033[0;31m"
#define AZUL "\033[0;34m"
#define RESET "\033[0m"

char matriz[34][66];

void corrigindoMatriz();
void imprimeMatriz();
void troca(char *a, char *b);
void calculoFisica();



int main()
{
    int quantidadeFrames, frame, x, y;
    corrigindoMatriz();
    char novaParticula;

    scanf("%d", &quantidadeFrames);

    int contadorFrames = 0;
    while (contadorFrames < quantidadeFrames)
    {
        int nLido = scanf(" %d: %d %d %c", &frame, &x, &y, &novaParticula);
        x++, y++;

        if (nLido == EOF) 
        {
            frame = quantidadeFrames;
        }

        // Calcula todos os frames até o próximo frame onde queremos criar
        // uma partícula.
        while (contadorFrames < frame) 
        {
            printf("\e[2J"); // clear
	        printf("\e[?25l"); // hide cursor
            printf("frame: %d\n", contadorFrames + 1);
            imprimeMatriz();
            calculoFisica();
            usleep(50000);

            contadorFrames++;
        }

        // Se há uma particula a ser criada, crie ela.
        if (nLido != EOF) 
        {
            matriz[y][x] = novaParticula;
        }
    }
    printf("\e[?25h");
    return 0;
}



void corrigindoMatriz()
{
    for (int i = 0; i < 34; i++)
    {
        for (int j = 0; j < 66; j++)
        {
            if (i == 0 || i == 33 || j == 0 || j == 65)
            {
                matriz[i][j] = '@';
            }
            else
            {
                matriz[i][j] = ' ';
            }
        }
    }
}


void imprimeMatriz()
{
    for (int i = 0; i < 34; i++)
    {
        for (int j = 0; j < 66; j++)
        {
            switch(matriz[i][j]){
				case '~':
					printf("%s~%s", AZUL, RESET);					
					break;
				case '#':
					printf("%s#%s", AMARELO, RESET);
					break;
                case '@':
                    printf("%s@%s", VERMELHO, RESET);
                    break;
				default:
					printf("%c", matriz[i][j]);
			}
        }
        printf("\n");
    }
}


void troca(char *a, char *b)
{
    char temporario;

    temporario = *a;
    *a = *b;
    *b = temporario;
}


void calculoFisica()
{
    char matrizCopia[34][66];
    for (int i = 0; i < 34; i++)
    {
        for (int j = 0; j < 66; j++)
        {
            matrizCopia[i][j] = matriz[i][j];
        }
    } 

    for (int i = 1; i < 33; i++)
    {
        for (int j = 1; j < 65; j++)
        {
            char comparador1 = i == 32 ? '@' : matriz[i + 1][j];
            char comparador2 = (i == 32 || j == 1) ? '@' : matriz[i + 1][j - 1];
            char comparador3 = (i == 32 || j == 64) ? '@' : matriz[i + 1][j + 1];
            char comparador4 = j == 1 ? '@' : matriz[i][j - 1];
            char comparador5 = j == 64 ? '@' : matriz[i][j + 1];

            if (matriz[i][j] == '#')
            {
                if (comparador1 == ' ' || comparador1 == '~')
                {
                    troca(&matrizCopia[i][j], &matrizCopia[i + 1][j]);
                }
                else if (comparador2 == ' ' || comparador2 == '~')
                {
                    troca(&matrizCopia[i][j], &matrizCopia[i + 1][j - 1]);
                }
                else if (comparador3 == ' ' || comparador3 == '~')
                {
                    troca(&matrizCopia[i][j], &matrizCopia[i + 1][j + 1]);
                }
            }
            else if (matriz[i][j] == '~')
            {
                if (comparador1 == ' ')
                {
                    troca(&matrizCopia[i][j], &matrizCopia[i + 1][j]);
                }
                else if (comparador2 == ' ')
                {
                    troca(&matrizCopia[i][j], &matrizCopia[i + 1][j - 1]);
                }
                else if (comparador3 == ' ')
                {
                    troca(&matrizCopia[i][j], &matrizCopia[i + 1][j + 1]);
                }
                else if (comparador4 == ' ')
                {
                    troca(&matrizCopia[i][j], &matrizCopia[i][j - 1]);
                }
                else if (comparador5 == ' ')
                {
                    troca(&matrizCopia[i][j], &matrizCopia[i][j + 1]);
                }
            }
            
            
        }
        
    }

    for (int i = 0; i < 34; i++)
    {
        for (int j = 0; j < 66; j++)
        {
            matriz[i][j] = matrizCopia[i][j];
        }
    } 
}