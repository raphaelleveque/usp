// Raphael Leveque 12542522
#include <stdio.h>

int main()
{
    int dia;
    scanf("%d", &dia);

    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
    printf("                ");

    for (int i = 1; i <= 30; i++)
    {
        if (i % 7 == 4)
        {
            printf("\n");
        }
        if (i == dia)
        {
            printf("(%2d)", i);
        }
        else
        {
            printf(" %2d ", i);
        }
    }
    

    return 0;
}