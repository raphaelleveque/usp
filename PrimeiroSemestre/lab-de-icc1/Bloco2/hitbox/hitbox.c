// Raphael Leveque 12542522

#include <stdio.h>
#include <stdbool.h>

bool hit_ou_miss(long long int intervalo[2][2], long long int interseccao[2]);

int main()
{
    long long int x1, largura1, x2, largura2;
    long long int y1, altura1, y2, altura2;

    scanf("%lld %lld %lld %lld", &x1, &y1, &largura1, &altura1);
    scanf("%lld %lld %lld %lld", &x2, &y2, &largura2, &altura2);

    long long int intervalo_x[2][2], intervalo_y[2][2];
    long long int interseccao_x[2] = {}, interseccao_y[2] = {};

    intervalo_x[0][0] = x1;
    intervalo_x[0][1] = largura1;
    intervalo_x[1][0] = x2;
    intervalo_x[1][1] = largura2;

    intervalo_y[0][0] = y1;
    intervalo_y[0][1] = altura1;
    intervalo_y[1][0] = y2;
    intervalo_y[1][1] = altura2;

    if (hit_ou_miss(intervalo_x, interseccao_x) && hit_ou_miss(intervalo_y, interseccao_y))
    {
        printf("HIT: %lld %lld %lld %lld\n", interseccao_x[0], interseccao_y[0], interseccao_x[1], interseccao_y[1]);
    }
    else
    {
        printf("MISS\n");
    }
    return 0;
}

bool hit_ou_miss(long long int intervalo[2][2], long long int interseccao[2])
{
    long long int coordenada1 = intervalo[0][0], largura1 = intervalo[0][1];
    long long int coordenada2 = intervalo[1][0], largura2 = intervalo[1][1];

    bool hit = false;

    if (coordenada1 < coordenada2)
    {
        if (coordenada1 + largura1 < coordenada2)
        {
            hit = false;
        }
        else if (coordenada1 + largura1 < coordenada2 + largura2)
        {
            hit = true;
            interseccao[0] = coordenada2;
            interseccao[1] = coordenada1 + largura1 - coordenada2;
        }
        else
        {
            hit = true;
            interseccao[0] = coordenada2;
            interseccao[1] = largura2;
        }
    }
    else
    {
        if (coordenada2 + largura2 < coordenada1)
        {
            hit = false;
        }
        else if (coordenada2 + largura2 < coordenada1 + largura1)
        {
            hit = true;
            interseccao[0] = coordenada1;
            interseccao[1] = coordenada2 + largura2 - coordenada1;
        }
        else
        {
            hit = true;
            interseccao[0] = coordenada1;
            interseccao[1] = largura1;
        }
    }
    return hit;
}
