#include <stdio.h>

int main()
{
    int ano;
    scanf("%d", &ano);

    ano % 4 == 0? printf("SIM\n") : printf("NAO\n");

    return 0;
}