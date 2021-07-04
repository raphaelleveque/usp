#include <stdio.h>
#include <time.h>

char matriz[32][64];

void corrigindoMatriz();
void imprimeMatriz();
void troca(char *a, char *b);
void calculoFisica();


void msleep(long msec){
    struct timespec ts;

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    nanosleep(&ts, &ts);
}

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

        if (nLido == EOF) 
        {
            frame = quantidadeFrames;
        }

        // Calcula todos os frames até o próximo frame onde queremos criar
        // uma partícula.
        while (contadorFrames < frame) 
        {
            system("clear && printf '\e[3J'");
            printf("frame: %d\n", contadorFrames + 1);
            imprimeMatriz();
            calculoFisica();
            msleep(150);
            contadorFrames++;
        }

        // Se há uma particula a ser criada, crie ela.
        if (nLido != EOF) 
        {
            matriz[y][x] = novaParticula;
        }
    }
    return 0;
}



void corrigindoMatriz()
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            matriz[i][j] = ' ';
        }
    }
}


void imprimeMatriz()
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            printf("%c", matriz[i][j]);
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
    char matrizCopia[32][64];
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            matrizCopia[i][j] = matriz[i][j];
        }
    } 

    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            char comparador1 = i == 31 ? '@' : matriz[i + 1][j];
            char comparador2 = (i == 31 || j == 0) ? '@' : matriz[i + 1][j - 1];
            char comparador3 = (i == 31 || j == 63) ? '@' : matriz[i + 1][j + 1];
            char comparador4 = j == 0 ? '@' : matriz[i][j - 1];
            char comparador5 = j == 63 ? '@' : matriz[i][j + 1];

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

    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            matriz[i][j] = matrizCopia[i][j];
        }
    } 
}