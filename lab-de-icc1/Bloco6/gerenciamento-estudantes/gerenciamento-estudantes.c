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
void searchIdentifier(Students *studentList, int numberOfStudents, int command, void *identifierToFind);
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
            searchIdentifier(studentList, currentStudent, 1, &identifierToFind);
        }
        else if (command == 2)
        {
            char *studentCourse;
            studentCourse = readLine();
            searchIdentifier(studentList, currentStudent, 2, studentCourse);
        }
        else if (command == 3)
        {
            for (int i = 0; i < currentStudent; i++)
            {
                printStudentInformations(studentList, i);
            }
            
        }
        
        
        
    } while (command != -1);
    


    return 0;
}


char *readLine()
{
    scanf("%*[\n\r]s");
    char *string = malloc(sizeof(char));
    int caracteres = 0;
    int nmrMaxChar = 1;
    do
    {
        scanf("%c", &string[caracteres]);
        if (string[caracteres] == '\n' || string[caracteres] == EOF)
        {
            string[caracteres] = '\0';
        }
        caracteres++;
        if (caracteres == nmrMaxChar)
        {
            nmrMaxChar *= 2;
            string = realloc(string, (nmrMaxChar) * sizeof(char));
        }

    }while (string[caracteres-1] != '\0');

    string = realloc(string, (caracteres + 1) * sizeof(char));

    return string;
}

void searchIdentifier(Students *studentList, int numberOfStudents, int command, void *studentToFind)
{
    int *identifier;
    char *course;
    if (command == 1)
    {
        identifier = (int *)studentToFind;
    }
    else if (command == 2)
    {
        course = (char *)studentToFind;
    }
    
    
    int i;
    for (i = 0; i <= numberOfStudents; i++)
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
    printf("Nome: %s", studentList[studentPosition].name);
    printf("Curso: %s", studentList[studentPosition].course);
    printf("N USP: %d", studentList[studentPosition].identifier);
    printf("Idade: %d", studentList[studentPosition].age);
}