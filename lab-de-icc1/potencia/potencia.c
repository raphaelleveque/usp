#include <stdio.h>

int main()
{
    int base, expoente, resultado;
    scanf("%d %d", &base, &expoente);

    if (expoente == 0)
    {
        printf("1");
        return 0;
    }
    
    
    resultado = base;
    for (int i = 0; i < (expoente - 1); i++)
    {
        resultado = resultado * base;
    }
    printf("%d", resultado);

    return 0;
}