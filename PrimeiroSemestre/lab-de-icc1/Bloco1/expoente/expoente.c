#include <stdio.h>
#include <math.h>

int main()
{
    float num, expoente, resultado;
    
    scanf("%f", &num);
    scanf("%f", &expoente);

    resultado = pow(num, expoente);

    printf("%.4f\n", resultado);

    return 0;
}