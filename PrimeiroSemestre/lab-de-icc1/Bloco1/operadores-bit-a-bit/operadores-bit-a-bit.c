#include <stdio.h>

int main()
{
    unsigned int a, b;

    scanf("%d %d", &a, &b);

    printf("%d\n", a & b);
    printf("%d\n", a | b);
    printf("%d\n", a ^ b);
    printf("%d\n", ~ a);
    printf("%d\n", ~ b);
    printf("%d\n", a >> 2);
    printf("%d\n", b << 2);
}