#include "pilha.h"

int main(){
    pilha_t *p = create();

    elem c;
    do{
        pilha_t *p = create();
        while ((c = getchar()) != '\n' && c != EOF){
            if (c == ' ' || c == '\r') continue;
            p = push(p, &c);
        }
        printandoBalanceado(p);
    }while (c != EOF);


    return 0;
}