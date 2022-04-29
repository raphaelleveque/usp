#include "comandos.h"
#include "funcoesAuxiliares.h"

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
