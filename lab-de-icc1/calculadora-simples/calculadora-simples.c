#include <stdio.h>

int main()
{
    int a;
    char op;
    float b;

    scanf("%d", &a);
    scanf(" %c", &op);
    scanf("%f", &b);

    switch (op)
    {
    case '+':
        printf("%f\n", a + b);
        break;
    
    case '-':
        printf("%f\n", a - b);
        break;
    
    case '*':
        printf("%f\n", a * b);
        break;
    
    case '/':
        printf("%f\n", a / b);
        break;
    
    case '%':
        printf("%f\n", (a / b) * 100);
        break;
    }

    return 0;
}