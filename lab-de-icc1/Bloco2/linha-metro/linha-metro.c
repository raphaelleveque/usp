// Raphael Leveque 12542522
#include <stdio.h>

int main()
{
    int estacao_inicial;
    scanf("%d", &estacao_inicial);

    switch (estacao_inicial)
    {
    case 0:
        printf("* Morumbi");
        
    case 1:
        if(estacao_inicial != 1)
            printf("\n|\n");
        printf("* Butanta");
        
    case 2:
        if(estacao_inicial != 2)
            printf("\n|\n");
        printf("* Pinheiros");
        
    case 3:
        if(estacao_inicial != 3)
            printf("\n|\n");
        printf("* Faria Lima");
        
    case 4:
        if(estacao_inicial != 4)
            printf("\n|\n");
        printf("* Fradique Coutinho");
        
    case 5:
        if(estacao_inicial != 5)
            printf("\n|\n");
        printf("* Oscar Freire");
        break;
        
    case 6:
        if(estacao_inicial != 6)
            printf("\n|\n");
        printf("* Paulista");
        
    case 7:
        if(estacao_inicial != 7)
            printf("\n|\n");
        printf("* Higienopolis-Mackenzie");
        
    case 8:
        if(estacao_inicial != 8)
            printf("\n|\n");
        printf("* Republica");
    
    case 9:
        if(estacao_inicial != 9)
            printf("\n|\n");
        printf("* Luz");
        break;
    }
    return 0;
}