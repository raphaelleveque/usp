// Raphael Leveque 12542522

#include <stdio.h>
#include <stdbool.h>

void swap(long long int *a, long long int *b);
bool hit_ou_miss(long long int intervalo[2][2], long long int interseccao[2]);

int main()
{
    long long int intervalo_x[2][2], intervalo_y[2][2];
    long long int interseccao_x[2] = {}, interseccao_y[2] = {};

    scanf("%lld %lld %lld %lld", &intervalo_x[0][0], &intervalo_y[0][0], &intervalo_x[0][1], &intervalo_y[0][1]);
    scanf("%lld %lld %lld %lld", &intervalo_x[1][0], &intervalo_y[1][0], &intervalo_x[1][1], &intervalo_y[1][1]);

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

void swap(long long int *a, long long int *b)
{
    long long int temporario;

    temporario = *a;
    *a = *b;
    *b = temporario;
}

bool hit_ou_miss(long long int intervalo[2][2], long long int interseccao[2])
{
    long long int coordenada1 = intervalo[0][0], largura1 = intervalo[0][1];
    long long int coordenada2 = intervalo[1][0], largura2 = intervalo[1][1];

    bool hit = false;

    if (coordenada1 > coordenada2)
    {
        swap(&coordenada1, &coordenada2);
        swap(&largura1, &largura2);
    }

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
    
    return hit;
}


