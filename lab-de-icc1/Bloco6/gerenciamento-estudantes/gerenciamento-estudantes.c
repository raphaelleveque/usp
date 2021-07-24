#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct students
{
    int identifier;
    char *name;
    char *course;
    int age;
} Students;

char *readLine();
void searchStudent(Students *studentList, int numberOfStudents, int command, void *findStudent);
void printStudentInformations(Students *studentList, int studentPosition);

int main()
{
    Students *studentList = malloc(sizeof(Students));

    int currentStudent = 0;
    do
    {
        scanf("%d", &studentList[currentStudent].identifier);
        if (studentList[currentStudent].identifier == -1)
        {
            break;
        }
        studentList[currentStudent].name = readLine();
        studentList[currentStudent].course = readLine();
        scanf("%d", &studentList[currentStudent].age);
        currentStudent++;
        studentList = realloc(studentList, (currentStudent + 1) * sizeof(Students));

    } while (1);

    int command;
    do
    {
        scanf("%d", &command);
        if (command == 1)
        {
            int identifierToFind;
            scanf("%d", &identifierToFind);
            searchStudent(studentList, currentStudent, 1, &identifierToFind);
        }
        else if (command == 2)
        {
            char *studentCourse;
            studentCourse = readLine();
            searchStudent(studentList, currentStudent, 2, studentCourse);
            free(studentCourse);
        }
        else if (command == 3)
        {
            for (int i = 0; i < currentStudent; i++)
            {
                printStudentInformations(studentList, i);
            }
        }

    } while (command != -1);


    for (int i = 0; i < currentStudent; i++)
    {
        free(studentList[i].name);
        free(studentList[i].course);
    }
    free(studentList);

    return 0;
}

char *readLine()
{
    scanf("%*[\n\r]s");
    char *string = malloc(sizeof(char));
    int characters = 0;
    int maxChars = 1;
    do
    {
        scanf("%c", &string[characters]);
        if (string[characters] == '\n' || string[characters] == EOF)
        {
            string[characters] = '\0';
        }
        characters++;
        if (characters == maxChars)
        {
            maxChars *= 2;
            string = realloc(string, (maxChars) * sizeof(char));
        }

    } while (string[characters - 1] != '\0');

    string = realloc(string, (characters + 1) * sizeof(char));

    return string;
}

void searchStudent(Students *studentList, int numberOfStudents, int command, void *findStudent)
{
    int *identifier;
    char *course;
    if (command == 1)
    {
        identifier = (int *)findStudent;
    }
    else if (command == 2)
    {
        course = (char *)findStudent;
    }

    int i;
    for (i = 0; i < numberOfStudents; i++)
    {
        if (command == 1 && studentList[i].identifier == *identifier)
        {
            printStudentInformations(studentList, i);
            break;
        }
        else if (command == 2 && (!strcmp(studentList[i].course, course)))
        {
            printStudentInformations(studentList, i);
        }
    }
}

void printStudentInformations(Students *studentList, int studentPosition)
{
    printf("Nome: %s\n", studentList[studentPosition].name);
    printf("Curso: %s\n", studentList[studentPosition].course);
    printf("N USP: %d\n", studentList[studentPosition].identifier);
    printf("IDADE: %d\n\n", studentList[studentPosition].age);
}