#include <stdio.h>

int main()
{
    long long int a1, r, n;
    scanf("%lld %lld %lld", &a1, &r, &n);

    long long int an = a1 + (n - 1) * r;
    long long int soma = (n * (a1 + an)) / 2;

    printf("%lld\n", an);
    printf("%lld\n", soma);


    return 0;
}