#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **names = malloc(sizeof(char *));
    names[0] = malloc(sizeof(char));

    int currentLine = 0, currentCharacter = 0;

    int stopScanning;
    do
    {
        names[currentLine][currentCharacter] = getchar();

        int nextLine = (names[currentLine][currentCharacter] == '\n');
        stopScanning = (names[currentLine][currentCharacter] == '$');

        currentCharacter++;
        names[currentLine] = realloc(names[currentLine], (currentCharacter + 1) * sizeof(char));

        if (nextLine || stopScanning)
        {
            names[currentLine][currentCharacter - 1] = '\0';
            if (currentLine % 2 == 1)
            {
                char *lastName = NULL;

                for (int i = 0; names[currentLine - 1][i] != '\0'; i++)
                {
                    if (names[currentLine - 1][i] == ' ')
                    {
                        lastName = &names[currentLine - 1][i];
                    }
                }

                names[currentLine] = realloc(names[currentLine], (strlen(names[currentLine]) + strlen(lastName) + 1) * sizeof(char));
                strcat(names[currentLine], lastName);
            }
            if (nextLine)
            {
                currentLine++;
                currentCharacter = 0;

                names = realloc(names, (currentLine + 1) * sizeof(char *));
                for (int i = 0; i <= currentLine; i++)
                {
                    if (i == currentLine)
                    {
                        names[i] = malloc(sizeof(char));
                    }
                    else
                    {
                        names[i] = realloc(names[i], (strlen(names[i]) + 1) * sizeof(char));
                    }
                }
                continue;
            }
        }
    } while (!stopScanning);


    for (int i = 0; i <= currentLine; i++)
    {
        printf("%s\n", names[i]);
    }


    for (int i = 0; i <= currentLine; i++)
    {
        free(names[i]);
    }
    free(names);

    return 0;
}