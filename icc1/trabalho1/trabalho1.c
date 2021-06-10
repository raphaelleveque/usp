// Raphael Leveque 12542522
#include <stdio.h>

enum {
    HLT,
    ADD,
    MUL,
    CLT,
    CEQ,
    JMP,
    JEQ,
    CPY,
    PUT,
    PTN
};

int main()
{
    int tape[512];

    for (int i = 0; i < 512; i++)
    {
        scanf("%d", &tape[i]);
    }
    printf("Saida do programa:\n");
    int i = 0;
    while (tape[i] != HLT)
    {

        if (tape[i] == ADD)
        {
            int arg1 = tape[i+1];
            int arg2 = tape[i+2];
            int arg3 = tape[i+3];

            tape[arg3] = tape[arg1] + tape[arg2];
            i = i + 4;
        }
        else if (tape[i] == MUL)
        {
            int arg1 = tape[i+1];
            int arg2 = tape[i+2];
            int arg3 = tape[i+3];

            tape[arg3] = tape[arg1] * tape[arg2];
            i = i + 4;
        }
        else if (tape[i] == CLT)
        {
            int arg1 = tape[i+1];
            int arg2 = tape[i+2];
            int arg3 = tape[i+3];

            tape[arg3] = tape[arg1] < tape[arg2] ? 1 : 0;
            i = i + 4;
        }
        else if (tape[i] == CEQ)
        {
            int arg1 = tape[i+1];
            int arg2 = tape[i+2];
            int arg3 = tape[i+3];

            tape[arg3] = tape[arg1] == tape[arg2] ? 1 : 0;
            i = i + 4;
        }
        else if (tape[i] == JMP)
        {
            int arg1 = tape[i+1];
            
            i = tape[arg1];
        }
        else if (tape[i] == JEQ)
        {
            int arg1 = tape[i+1];
            int arg2 = tape[i+2];

            int should_jump = (tape[arg1]);
            if (should_jump)
            {
                i = tape[arg2];
            }
            else
            {
                i = i + 3;
            }
        }
        else if (tape[i] == CPY)
        {
            int arg1 = tape[i+1];
            int arg2 = tape[i+2];

            tape[arg2] = tape[arg1];
            i = i + 3;
        }
        else if (tape[i] == PUT)
        {
            int arg1 = tape[i+1];

            printf("%c", tape[arg1]);
            i = i + 2;
        }
        else if (tape[i] == PTN)
        {
            int arg1 = tape[i+1];

            printf("%d", tape[arg1]);
            i = i + 2;
        }     
    }
    printf("\nEstado final da fita:\n");
    
    for (int i = 0; i < 512; i++)
    {
        printf("%d\n", tape[i]);
    }

    return 0;
}