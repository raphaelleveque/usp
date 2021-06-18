#include <stdio.h>

int main ()
{  
    double a1, q, n;
    scanf("%lf %lf %lf", &a1, &q, &n);

    float q_pow_n = q;
    for (int i = 0; i < (n - 1); i++)
    {
        q_pow_n = q_pow_n * q;
    }
    float an = a1 * (q_pow_n/q);
    float soma = (a1 * (q_pow_n - 1)) / (q - 1);
    
    printf("%.2f\n", an);
    printf("%.2f\n", soma);

    return 0;
}