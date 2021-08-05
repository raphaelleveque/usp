#include <stdio.h>
#include <stdlib.h>

int main()
{
    char numberOrOperator;
    double *stack = NULL;
    double *stackPointer = NULL;
    int stackSize = 0;

    while ((numberOrOperator = getchar()) != EOF)
    {
        if (numberOrOperator >= '0' && numberOrOperator <= '9')
        {
            stackSize++;
            stack = realloc(stack, stackSize * sizeof(double));
            stackPointer = &stack[stackSize - 1];
            ungetc(numberOrOperator, stdin);
            scanf("%lf", stackPointer);
        }
        else if (numberOrOperator == '+')
        {
            stackPointer--;
            *stackPointer = *stackPointer + *(stackPointer + 1);
            stackSize--;
            stack = realloc(stack, stackSize * sizeof(double));
            stackPointer = &stack[stackSize - 1];
        }
        else if (numberOrOperator == '-')
        {
            stackPointer--;
            *stackPointer = *stackPointer - *(stackPointer + 1);
            stackSize--;
            stack = realloc(stack, stackSize * sizeof(double));
            stackPointer = &stack[stackSize - 1];
        }
        else if (numberOrOperator == '*')
        {
            stackPointer--;
            *stackPointer = *stackPointer * *(stackPointer + 1);
            stackSize--;
            stack = realloc(stack, stackSize * sizeof(double));
            stackPointer = &stack[stackSize - 1];
        }
        else if (numberOrOperator == '/')
        {
            stackPointer--;
            *stackPointer = *stackPointer / *(stackPointer + 1);
            stackSize--;
            stack = realloc(stack, stackSize * sizeof(double));
            stackPointer = &stack[stackSize - 1];
        }
    }
    printf("Resultado: %.6lf\n", stack[0]);

    free(stack);

    return 0;
}