#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, contador = 0;
    bool div11;
    bool div13;
    bool div19;


    scanf("%d", &n);


    if (n % 11 == 0){
        div11 = true;
        contador++;
    }

    if (n % 13 == 0){
        div13 = true;
        contador++;
    }

    if (n % 19 == 0){
        div19 = true;
        contador++;
    }



    switch (contador)
    {

    case 1: 
            if (div11){
                printf("BaBa");
            }

            else if (div13){
                printf("BaDum");
            }
            
            else{
                printf("BaTss");
            }  
        break;


    case 2:
            if(div11 & div13){
                printf("BaDumDum");
            }

            else if(div11 & div19){
                printf("BaDumTss");
            }
            else{
                printf("DumDumTss");
            }
        break;


    case 3:
        printf("BaDumTssTss");
        break;


    default:
        printf("%d", n);
        break;
    }


    return 0;
}