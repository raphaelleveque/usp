#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *jit = NULL;
    jit = fopen("jit-gerado.c", "w");

    fprintf(jit, "#include <stdio.h>\n\n");
    fprintf(jit, "int main(){\n");
    fprintf(jit, "\tchar memory[30000] = {};\n");
    fprintf(jit, "\tint i = 0;\n\n");


    char bfoperation;
    while ((bfoperation = getchar()) != EOF)
    {
        switch (bfoperation)
        {
        case '+':
            fprintf(jit, "\tmemory[i]++;\n");
            break;
        case '-':
            fprintf(jit, "\tmemory[i]--;\n");
            break;
        case '>':
            fprintf(jit, "\ti++;\n");
            break;
        case '<':
            fprintf(jit, "\ti--;\n");
            break;
        case '.':
            fprintf(jit, "\tputchar(memory[i]);\n");
            break;
        case '[':
            fprintf(jit, "\twhile(memory[i]) {\n");
            break;
        case ']':
            fprintf(jit, "\t}\n");
            break;
        default:
            break;
        }
    }
    fprintf(jit, "\n\n\tprintf(\"\\n\");\n");
    fprintf(jit, "\tfor (int j = 0; j < 30000; j++) {\n");
    fprintf(jit, "\t\tif (memory[j] != 0) {\n");
    fprintf(jit, "\t\t\tprintf(\"%%d \", memory[j]);\n");
    fprintf(jit, "\t\t}\n");
    fprintf(jit, "\t}\n\n");


    fprintf(jit, "\n\nreturn 0;\n");
    fprintf(jit, "}");
    fclose(jit);
    
    system("gcc jit-gerado.c -o jit-exe");
    system("./jit-exe");

    return 0;
}