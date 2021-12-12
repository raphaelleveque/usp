#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<unistd.h>

char **readingMaze(char **maze, int rows, int columns, FILE *input, int *peopleSearchingYou, int *validPaths);
char *readLine();
int mazeRunner(char **maze, int rows, int columns, int currentColumn, int currentRow, int *visitedPaths);
void printingMaze(char **maze, int rows, int columns);

int main()
{
    int rows, columns;
    int initialColumn, initialRow;

    char *inputFileName = readLine();

    FILE *input = fopen(inputFileName, "r");

    fscanf(input, "%d %d", &rows, &columns);
    fscanf(input, "%d %d", &initialRow, &initialColumn);

    int peopleSearchingYou = 0, validPaths = 0;

    char **maze = malloc(sizeof(char *));
    maze = readingMaze(maze, rows, columns, input, &peopleSearchingYou, &validPaths);

    maze[initialRow][initialColumn] = '*';
    int visitedPaths = 1;

    printingMaze(maze, rows, columns);
    mazeRunner(maze, rows, columns, initialColumn, initialRow, &visitedPaths);

    printingMaze(maze, rows, columns);
    printf("\nVoce escapou de todos! Ninguem conseguiu te segurar!\n");
    printf("Veja abaixo os detalhes da sua fuga:\n");
    printf("----Pessoas te procurando: %d\n", peopleSearchingYou);
    printf("----Numero total de caminhos validos:   %d\n", validPaths);
    printf("----Numero total de caminhos visitados: %d\n", visitedPaths);

    double exploration = (visitedPaths / (double)validPaths) * 100;
    int temporaryExploration = exploration;
    exploration = temporaryExploration;
    printf("----Exploracao total do labirinto: %.1lf%%\n", exploration);

    fclose(input);
    free(inputFileName);
    for (int i = 0; i < rows; i++)
    {
        free(maze[i]);
    }
    free(maze);

    printf("\e[?25h"); // show cursor
    return 0;
}

char **readingMaze(char **maze, int rows, int columns, FILE *input, int *peopleSearchingYou, int *validPaths)
{
    maze = realloc(maze, rows * sizeof(char *));
    for (int i = 0; i < rows; i++)
    {
        maze[i] = malloc(columns * sizeof(char));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            fscanf(input, " %c", &maze[i][j]);
            if (maze[i][j] == '#')
            {
                (*peopleSearchingYou)++;
            }
            else if (maze[i][j] == '.')
            {
                (*validPaths)++;
            }
        }
    }

    return maze;
}

char *readLine()
{
    scanf("%*[\n\r]s");
    char *string = malloc(sizeof(char));
    int characters = 0;
    int numberMaxChar = 1;
    do
    {
        scanf("%c", &string[characters]);
        if (string[characters] == '\n' || string[characters] == EOF)
        {
            string[characters] = '\0';
        }
        characters++;
        if (characters == numberMaxChar)
        {
            numberMaxChar *= 2;
            string = realloc(string, (numberMaxChar) * sizeof(char));
        }

    } while (string[characters - 1] != '\0');

    string = realloc(string, (characters + 1) * sizeof(char));

    return string;
}

int mazeRunner(char **maze, int rows, int columns, int currentColumn, int currentRow, int *visitedPaths)
{

    bool left = (currentColumn == 0);
    bool right = (currentColumn == columns - 1);
    bool top = (currentRow == 0);
    bool bottom = (currentRow == rows - 1);

    if ((left || right || top || bottom) && maze[currentRow][currentColumn] == '*')
    {
        return -1;
    }

    if (!top && maze[currentRow - 1][currentColumn] == '.')
    {
        maze[currentRow - 1][currentColumn] = '*';
        (*visitedPaths)++;
        printingMaze(maze, rows, columns);

        int stopRecursion = mazeRunner(maze, rows, columns, currentColumn, currentRow - 1, visitedPaths);
        if (stopRecursion == -1)
        {
            return -1;
        }
    }
    if (!right && maze[currentRow][currentColumn + 1] == '.')
    {
        maze[currentRow][currentColumn + 1] = '*';
        (*visitedPaths)++;
        printingMaze(maze, rows, columns);

        int stopRecursion = mazeRunner(maze, rows, columns, currentColumn + 1, currentRow, visitedPaths);
        if (stopRecursion == -1)
        {
            return -1;
        }
    }
    if (!bottom && maze[currentRow + 1][currentColumn] == '.')
    {
        maze[currentRow + 1][currentColumn] = '*';
        (*visitedPaths)++;
        printingMaze(maze, rows, columns);

        int stopRecursion = mazeRunner(maze, rows, columns, currentColumn, currentRow + 1, visitedPaths);
        if (stopRecursion == -1)
        {
            return -1;
        }
    }
    if (!left && maze[currentRow][currentColumn - 1] == '.')
    {
        maze[currentRow][currentColumn - 1] = '*';
        (*visitedPaths)++;
        printingMaze(maze, rows, columns);

        int stopRecursion = mazeRunner(maze, rows, columns, currentColumn - 1, currentRow, visitedPaths);
        if (stopRecursion == -1)
        {
            return -1;
        }
    }
    return 1;
}

void printingMaze(char **maze, int rows, int columns)
{
    printf("\n\n\n");
    printf("\e[2J"); // clear
	printf("\e[?25l"); // hide cursor
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (maze[i][j] == '*')
            {
                printf("%s%c%s", "\033[0;33m", maze[i][j], "\033[0m");
            }
            else if(maze[i][j] == '#')
            {
                printf("%s%c%s", "\e[0;32m", maze[i][j], "\033[0m");
            }
            else
            {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n\n\n");
    usleep(150000);
}