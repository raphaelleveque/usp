#include <stdio.h>
#include <math.h>

int main()
{
    double numeros[4], resultado;
    for (int i = 0; i < 4; i++)
    {
        double x;
        scanf("%lf", &x);
        numeros[i] = x;
    }
    float menor = numeros[0];
    for (int i = 0; i < 4; i++)
    {
        if (menor > numeros[i])
        {
            menor = numeros[i];
        }
        
    }
    resultado = (numeros[0] + numeros[1] + numeros[2] + numeros[3] - menor)  / 3.0;
    printf("%.4lf\n", resultado);


    return 0;
}