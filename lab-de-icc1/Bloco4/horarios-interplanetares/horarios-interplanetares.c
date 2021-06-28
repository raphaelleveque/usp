#include <stdio.h>
#include <string.h>

void calculo_terra(unsigned long long int *tempo, char planeta[9], unsigned long long int tempo_decrescente[4]);
void calculo_jupiter(unsigned long long int *tempo, char planeta[9], unsigned long long int tempo_decrescente[4]);
void calculo_venus(unsigned long long int *tempo, char planeta[9], unsigned long long int tempo_decrescente[4]);
void calculo_mercurio(unsigned long long int *tempo, char planeta[9], unsigned long long int tempo_decrescente[4]);


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
        calculo_terra(&tempo, planeta, tempo_decrescente);
    }
    else if (!strcmp(planeta, "Jupiter"))
    {
        calculo_jupiter(&tempo, planeta, tempo_decrescente);
    }
    else if (!strcmp(planeta, "Venus"))
    {
        calculo_venus(&tempo, planeta, tempo_decrescente);
    }
    else if (!strcmp(planeta, "Mercurio"))
    {
        calculo_mercurio(&tempo, planeta, tempo_decrescente);
    }

    printf("%llu segundos no planeta %s equivalem a:\n", tempo, planeta);
    printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", tempo_decrescente[0], tempo_decrescente[1], tempo_decrescente[2], tempo_decrescente[3]);

    

    return 0;
}



void calculo_terra(unsigned long long int *tempo, char planeta[9], unsigned long long int tempo_decrescente[4])
{
    unsigned long long int tempo_total = *tempo;
    if (*tempo >= 86400)
    {
        tempo_decrescente[0] = (*tempo - (*tempo % 86400)) / 86400;
        *tempo = *tempo % 86400;
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



void calculo_jupiter(unsigned long long int *tempo, char planeta[9], unsigned long long int tempo_decrescente[4])
{
    unsigned long long int tempo_total = *tempo;
    if (*tempo >= 35760)
    {
        tempo_decrescente[0] = (*tempo - (*tempo % 35760)) / 35760;
        *tempo = *tempo % 35760;
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



void calculo_venus(unsigned long long int *tempo, char planeta[9], unsigned long long int tempo_decrescente[4])
{
    unsigned long long int tempo_total = *tempo;
    if (*tempo >= 20995200)
    {
        tempo_decrescente[0] = (*tempo - (*tempo % 20995200)) / 20995200;
        *tempo = *tempo % 20995200;
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



void calculo_mercurio(unsigned long long int *tempo, char planeta[9], unsigned long long int tempo_decrescente[4])
{
    unsigned long long int tempo_total = *tempo;
    if (*tempo >= 5068800)
    {
        tempo_decrescente[0] = (*tempo - (*tempo % 5068800)) / 5068800;
        *tempo = *tempo % 5068800;
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


