#include <stdio.h>

int main()
{
    int bolinha, racao, resultado;
    scanf("%d %d", &bolinha, &racao);

    resultado = (bolinha * 5) - (racao * 3);

    if (resultado >= 0 && resultado < 30 )
    {
        printf("B\n");
    }
    else if (resultado < 0)
    {
        printf("R\n");
    }
    else
        printf("P\n");
    
    

    return 0;
}