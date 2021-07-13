#include <stdio.h>
#include <stdlib.h>

int main()
{
    char numberOrOperator;
    double stack[15] = {};
    int i = 0;
    
    while ((numberOrOperator = getchar()) != EOF)
    {
        if (numberOrOperator >= '0' && numberOrOperator <= '9')
        {
            ungetc(numberOrOperator, stdin);
            scanf("%lf", &stack[i]);
            i++;
        }
        else if (numberOrOperator == ' ' );
        else
        {
            if (numberOrOperator == '+')
            {
                i -= 2;
                stack[i] = stack[i] + stack[i + 1];
                i++;
            }
            else if (numberOrOperator == '-')
            {
                i -= 2;
                stack[i] = stack[i] - stack[i + 1];
                i++;
            }
            else if (numberOrOperator == '*')
            {
                i -= 2;
                stack[i] = stack[i] * stack[i + 1];
                i++;
            }
            else if (numberOrOperator == '/')
            {
                i -= 2;
                stack[i] = stack[i] / stack[i + 1];
                i++;
            }

        }
        
        
    }
    printf("Resultado: %.6lf", stack[i - 1]);

    return 0;
}