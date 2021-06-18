// Raphael Leveque 12542522
#include <stdio.h>

int main()
{
    int n, m, p;
    scanf("%d %d %d", & n, &m, &p);

    for (int i = 0, contador = 1; i < n; contador++)
    {
        if (contador * 3 <= n - i)
        {
            for (int j = 0; j < contador; j++)
            {
                if (i % m == p - 1)
                {
                    if (contador == 1)
                    {
                        printf("1 pinguim\n");
                    }
                    else
                    {
                        printf("%d pinguins\n", contador);
                    }
                }              
                i++;
            }
            for (int j = 0; j < contador; j++)
            {
                if (i % m == p - 1)
                {
                    printf("no gelo\n");
                }
                i++;
            }
            for (int j = 0; j < contador; j++)
            {
                if (i % m == p - 1)
                {
                    printf("uhuu!\n");
                }   
                i++;
            }  
        }
        else
        {
            while(i < n)
            {
                for (int j = 0; j < contador; j++)
                {
                    if (i == n)
                    {
                        return 0;
                    }
                    if (i % m == p - 1)
                    {
                        if (contador == 1)
                        {
                            printf("1 pinguim\n");
                        }
                        else
                        {
                            printf("%d pinguins\n", contador);
                        } 
                    } 
                    i++;
                }
                for (int j = 0; j < contador; j++)
                {
                    if (i == n)
                    {
                        return 0;
                    }
                    if (i % m == p - 1)
                    {
                        printf("no gelo\n");
                    }
                    i++;
                }
                for (int j = 0; j < contador; j++)
                {
                    if (i == n)
                    {
                        return 0;
                    }
                    if (i % m == p - 1)
                    {
                        printf("uhuu!\n");
                    }
                    i++;
                }
            }            
        }        
    }
    return 0;
}