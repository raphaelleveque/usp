#ifndef COMANDOS_H
#define COMANDOS_H

typedef struct Person {
    char first_name[51], last_name[51];
    char email[81], nationality[51];
    int age;
} Person_t;


void command_one(const char file_name[51]);
void command_two(const char file_name[51]);
void command_three(const char file_name[51]);

#endif
