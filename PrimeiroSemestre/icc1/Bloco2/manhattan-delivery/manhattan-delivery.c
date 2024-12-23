// Raphael Leveque 12542522
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double distancia_diagonal(int x, int x0, int y, int y0)
{
    double distancia_diagonal;
    distancia_diagonal = sqrt(pow(x - x0, 2) + pow(y - y0, 2));
    return distancia_diagonal;
}

double distancia_semiperimetro(int x, int x0, int y, int y0)
{
    double distancia_semiperimetro;
    distancia_semiperimetro = abs((x) - (x0)) + abs((y) - (y0));
    return distancia_semiperimetro;
}

int main()
{
    int numero_de_pontos;
    scanf("%d", &numero_de_pontos);
        if (numero_de_pontos <= 0)
        {
            printf("Falha no processamento dos dados.\n");
            return 0;
        }

    int pontosX[numero_de_pontos], pontosY[numero_de_pontos], pontosI[numero_de_pontos];
    for (int i = 0; i < numero_de_pontos; i++)
    {
        scanf("%d", &pontosX[i]);
        scanf("%d", &pontosY[i]);
        scanf("%d", &pontosI[i]);
        if (pontosI[i] > 1 || pontosI[i] < -1)
        {
            printf("Falha no processamento dos dados.\n");
            return 0;
        }
    }

    double distancia_euclides = 0.0, distancia_hermann = 0.0;
    int baldio = 0, residencial = 0, parque = 0;
    for (int i = 0; i < numero_de_pontos; i++)
    {
        if (pontosI[i] == -1)
        {
            baldio++;
        }
        else if (pontosI[i] == 0)
        {
            residencial++;
        }
        else
        {
            parque++;
            if (i != numero_de_pontos - 1)
            {
            distancia_euclides +=  distancia_diagonal(pontosX[i + 1], pontosX[i], pontosY[i + 1], pontosY[i]);
            distancia_hermann += distancia_semiperimetro(pontosX[i + 1], pontosX[i], pontosY[i + 1], pontosY[i]);
            }
        }
    }
    if (pontosI[numero_de_pontos - 1] == 1)
    {
        distancia_euclides +=  distancia_diagonal(pontosX[numero_de_pontos - 1], pontosX[0], pontosY[numero_de_pontos - 1], pontosY[0]);
        distancia_hermann +=  distancia_semiperimetro(pontosX[numero_de_pontos - 1], pontosX[0], pontosY[numero_de_pontos - 1], pontosY[0]);
    }
    
    double diferenca_distancia = distancia_hermann - distancia_euclides;
    printf("Ao todo, foi passado por %d terrenos baldios, %d terrenos residenciais e %d parques.\nA diferenca total de distancia percorrida foi de %.2lf metros.\n", baldio, residencial, parque, diferenca_distancia);

    return 0;
}