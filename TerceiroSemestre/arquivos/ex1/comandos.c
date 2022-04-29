#include "comandos.h"
#include "funcoesAuxiliares.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Essa função executa o primeiro comando, que lê dados do stdin e os salva no arquivo
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


// Essa função serve para ler os dados do registro e imprimi-los
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


// Essa função busca por uma pessoa específica no registro
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
