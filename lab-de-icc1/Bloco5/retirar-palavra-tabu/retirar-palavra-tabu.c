#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char tabooWord[20] = {};
    scanf("%s", tabooWord);
    int sizeOfTabooWord = strlen(tabooWord);

    char *phrase = malloc(2 * sizeof(char));
    int numberOfChars = 0;
    scanf("%*[\n]");
    while ((phrase[numberOfChars] = getchar()) != '$')
    {
        numberOfChars++;
        if (numberOfChars % 2 == 0)
        {
            phrase = realloc(phrase, (2 * numberOfChars) * sizeof(char));
        }
    }
    phrase = realloc(phrase, (numberOfChars + 2) * sizeof(char));
    phrase[numberOfChars] = '\0';

    char *findTabooWord = malloc((numberOfChars + 1) * sizeof(char));

    int tabooCounter = 0;
    do
    {
        findTabooWord = strstr(phrase, tabooWord);

        if (findTabooWord == NULL)
        {
            break;
        }
        tabooCounter++;

        int i;
        for (i = 0; findTabooWord != &phrase[i]; i++);

        char *newPhrase = calloc((numberOfChars + 1), sizeof(char));
        strncpy(newPhrase, phrase, i);
        strcat(newPhrase, &phrase[i + sizeOfTabooWord]);

        strcpy(phrase, newPhrase);

        free(newPhrase);
    } while (1);

    printf("A palavra tabu foi encontrada %d vezes\n", tabooCounter);
    printf("Frase: %s", phrase);

    free(phrase);
    free(findTabooWord);

    return 0;
}