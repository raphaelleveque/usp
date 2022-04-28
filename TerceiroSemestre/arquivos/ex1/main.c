#include <stdio.h>
#include <string.h>
#include "funcoesFornecidas.h"

typedef struct Person {
    char first_name[51], last_name[51];
    char email[81], nationality[51];
    int age;
} Person_t;

void fill_with_dollars(FILE *fp, int len) {
    char *garbage = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++)
        garbage[i] = '$';
    
    fwrite(garbage, sizeof(char), len, fp);
    free(garbage);
}

void write_in_file(FILE *fp, Person_t *person) {
    fwrite(person->first_name, sizeof(char), strlen(person->first_name) + 1, fp);
    fill_with_dollars(fp, 51 - (strlen(person->first_name) + 1));

    fwrite(person->last_name, sizeof(char), strlen(person->last_name) + 1, fp);
    fill_with_dollars(fp, 51 - (strlen(person->last_name) + 1));

    fwrite(person->email, sizeof(char), strlen(person->email) + 1, fp);
    fill_with_dollars(fp, 81 - (strlen(person->email) + 1));

    fwrite(person->nationality, sizeof(char), strlen(person->nationality) + 1, fp);
    fill_with_dollars(fp, 51 - (strlen(person->nationality) + 1)); 

    fwrite(&person->age, sizeof(int), 1, fp);
}



void command_one(const char file_name[51]) {
    Person_t person;
    FILE *fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("Falha no processamento do arquivo\n");
        exit(EXIT_SUCCESS);
    }
    int n_registers;
    scanf("%d ", &n_registers);

    while (n_registers--) {
        read_line(person.first_name);
        read_line(person.last_name);
        read_line(person.email);
        read_line(person.nationality);
        scanf("%d", &person.age);
        write_in_file(fp, &person);
    }
    fclose(fp);
    binary_on_screen(file_name);
}






char* read_from_file(FILE *fp, int len, char *string) {
    if(fread(string, sizeof(char), len, fp) == 0 ) {
        printf("Não foi possível ler um campo do registro\n");
        exit(EXIT_SUCCESS);
    }
    return string;
}

void print_person(const Person_t* person) {
    printf("Firstname: %s\n", person->first_name);
    printf("Lastname: %s\n", person->last_name);
    printf("Email: %s\n", person->email);
    printf("Nationality: %s\n", person->nationality);
    printf("Age: %d\n\n", person->age);
}




void command_two(const char file_name[51]) {
    Person_t person;
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Falha no processamento do arquivo\n");
        exit(EXIT_SUCCESS);
    }
    char names[51], email[81];
    char buff;
    while (fread(&buff, sizeof(char), 1, fp) != 0) {
        fseek(fp, -1, SEEK_CUR);
        strcpy(person.first_name, read_from_file(fp, 51, names));
        strcpy(person.last_name, read_from_file(fp, 51, names));
        strcpy(person.email, read_from_file(fp, 81, email));
        strcpy(person.nationality, read_from_file(fp, 51, names));
        fread(&person.age, sizeof(int), 1, fp);
        print_person(&person);
    }

    fclose(fp);
}






void command_three(const char file_name[51]) {
    const int byteoffset = 51 + 51 + 81 + 51 + sizeof(int);

    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Falha no processamento do arquivo\n");
        exit(EXIT_SUCCESS);
    }

    int rrn;
    scanf("%d", &rrn);
    if (fseek(fp, (rrn * byteoffset), SEEK_SET) != 0) {
        printf("Não foi possível ler o arquivo\n");
        exit(EXIT_SUCCESS);
    }

    Person_t person;
    char names[51], email[81];
    strcpy(person.first_name, read_from_file(fp, 51, names));
    strcpy(person.last_name, read_from_file(fp, 51, names));
    strcpy(person.email, read_from_file(fp, 81, email));
    strcpy(person.nationality, read_from_file(fp, 51, names));
    fread(&person.age, sizeof(int), 1, fp);
    print_person(&person);

}




int main() {
    int command;
    scanf("%d ", &command);
    char file_name[51];
    read_line(file_name);
    

    switch (command) {
    case 1:
        command_one(file_name);
        break;
    case 2:
        command_two(file_name);
        break; 
    case 3:
        command_three(file_name);
        break;
    
    default:
        printf("Invalid Command\n");
        break;
    }

    return 0;
}