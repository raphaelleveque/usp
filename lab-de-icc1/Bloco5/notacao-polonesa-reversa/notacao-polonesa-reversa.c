#include <stdio.h>
#include <stdlib.h>

int main()
{
    char numberOrOperator;
    double *stack = malloc(sizeof(double));
    double *stackPointer = NULL;
    int stackSize = 0;
    
    while ((numberOrOperator = getchar()) != EOF)
    {
        if (numberOrOperator >= '0' && numberOrOperator <= '9')
        {
            ungetc(numberOrOperator, stdin);
            scanf("%lf", &stack[stackSize]);
            stackSize++;
            stack = realloc(stack, (stackSize + 1) * sizeof(double));
            stackPointer = &stack[stackSize];
        }
        else if (numberOrOperator == ' ' );
        else
        {
            if (numberOrOperator == '+')
            {
                stackPointer -= 2;
                *stackPointer = *stackPointer + *(stackPointer + 1);
                stackPointer ++;
                stackSize--;
            }
            else if (numberOrOperator == '-')
            {
                stackPointer -= 2;
                *stackPointer = *stackPointer - *(stackPointer + 1);
                stackPointer ++;
                stackSize--;
            }
            else if (numberOrOperator == '*')
            {
                stackPointer -= 2;
                *stackPointer = *stackPointer * *(stackPointer + 1);
                stackPointer ++;
                stackSize--;
            }
            else if (numberOrOperator == '/')
            {
                stackPointer -= 2;
                *stackPointer = *stackPointer / *(stackPointer + 1);
                stackPointer ++;
                stackSize--;
            }

        }
        
        
    }
    printf("Resultado: %.6lf\n", stack[0]);

    free(stack);

    return 0;
}