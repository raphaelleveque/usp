#include <stdio.h>
#include <stdlib.h>

int main()
{
    char numberOrOperator;
    double *stack = malloc(2 * sizeof(double));
    double *stackPointer;
    int stackSize = 0;
    
    while ((numberOrOperator = getchar()) != EOF)
    {
        if (numberOrOperator >= '0' && numberOrOperator <= '9')
        {
            ungetc(numberOrOperator, stdin);
            scanf("%lf", &stack[stackSize]);
            stackSize++;
            if (stackSize % 2 == 1)
            {
                stack = realloc(stack, (stackSize * 2 + 1) * sizeof(double));
            }
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
                stack = realloc(stack, stackSize * sizeof(double));
                stackSize--;
            }
            else if (numberOrOperator == '-')
            {
                stackPointer -= 2;
                *stackPointer = *stackPointer - *(stackPointer + 1);
                stackPointer ++;
                stack = realloc(stack, stackSize * sizeof(double));
                stackSize--;
            }
            else if (numberOrOperator == '*')
            {
                stackPointer -= 2;
                *stackPointer = *stackPointer * *(stackPointer + 1);
                stackPointer ++;
                stack = realloc(stack, stackSize * sizeof(double));
                stackSize--;
            }
            else if (numberOrOperator == '/')
            {
                stackPointer -= 2;
                *stackPointer = *stackPointer / *(stackPointer + 1);
                stackPointer ++;
                stack = realloc(stack, stackSize * sizeof(double));
                stackSize--;
            }

        }
        
        
    }
    printf("Resultado: %.6lf", stack[stackSize - 1]);

    return 0;
}