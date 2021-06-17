#include <iostream>
using namespace std;

void testando_baralho(int *a)
{
    int contador = 0;
    for (int i = 0; i < 13; i++)
    {
        if (a[i] == 2)
        {
            printf("erro\n");
            return;
        }
        else if (a[i] == 0)
        {
            contador++;
        }        
    }
    if (contador == 0)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", contador);
    }
}

int main()
{
    char s[55] = {};

    cin >> s;

    int c[13] = {}, e[13] = {}, u[13] = {}, p[13] = {};
    for (int i = 0; i < 54; i+=3)
    {
        if(s[i+2] == 'C')
        {
            int j = (s[i] - '0') * 10 + (s[i+1] - '0') - 1;
            c[j]++;
        }
        else if(s[i+2] == 'E')
        {
            int j = (s[i] - '0') * 10 + (s[i+1] - '0') - 1;
            e[j]++;
        }
        else if(s[i+2] == 'U')
        {
            int j = (s[i] - '0') * 10 + (s[i+1] - '0') - 1;
            u[j]++;
        }
        else
        {
            int j = (s[i] - '0') * 10 + (s[i+1] - '0') - 1;
            p[j]++;
        }
        
    }
    testando_baralho(c);
    testando_baralho(e);
    testando_baralho(u);
    testando_baralho(p);

    return 0;
}