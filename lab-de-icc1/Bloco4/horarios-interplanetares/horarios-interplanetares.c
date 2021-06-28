#include <stdio.h>
#include <string.h>

void calculo_tempo(unsigned long long int *tempo, char planeta[9], unsigned long long int tempo_decrescente[4], int *dia);

int main()
{
    unsigned long long int tempo;
    char planeta[9] = {};

    scanf("%llu", &tempo);
    scanf("%*[' ']s");


    for (int i = 0; i < 9; i++)
    {
        scanf("%c", &planeta[i]);
        if (planeta[i] == '\n')
        {
            planeta[i] = '\0';
            break;
        }
    }
    
    unsigned long long int tempo_decrescente[4] = {};

    if(!strcmp(planeta, "Terra"))
    {
        int dia = 86400;
        calculo_tempo(&tempo, planeta, tempo_decrescente, &dia);
    }
    else if (!strcmp(planeta, "Jupiter"))
    {
        int dia = 35760;
        calculo_tempo(&tempo, planeta, tempo_decrescente, &dia);
    }
    else if (!strcmp(planeta, "Venus"))
    {
        int dia = 20995200;
        calculo_tempo(&tempo, planeta, tempo_decrescente, &dia);
    }
    else if (!strcmp(planeta, "Mercurio"))
    {
        int dia = 5068800;
        calculo_tempo(&tempo, planeta, tempo_decrescente, &dia);
    }

    printf("%llu segundos no planeta %s equivalem a:\n", tempo, planeta);
    printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", tempo_decrescente[0], tempo_decrescente[1], tempo_decrescente[2], tempo_decrescente[3]);

    

    return 0;
}



void calculo_tempo(unsigned long long int *tempo, char planeta[9], unsigned long long int tempo_decrescente[4], int *dia)
{
    unsigned long long int tempo_total = *tempo;
    if (*tempo >= *dia)
    {
        tempo_decrescente[0] = (*tempo - (*tempo % *dia)) / *dia;
        *tempo = *tempo % *dia;
    }
    if (*tempo >= 3600)
    {
        tempo_decrescente[1] = (*tempo - (*tempo % 3600)) / 3600;
        *tempo = *tempo % 3600;
    }
    if (*tempo >= 60)
    {
        tempo_decrescente[2] = (*tempo - (*tempo % 60)) / 60;
        *tempo = *tempo % 60;
    }
    if (*tempo >= 1)
    {
        tempo_decrescente[3] = *tempo;
    }
    *tempo = tempo_total;
}