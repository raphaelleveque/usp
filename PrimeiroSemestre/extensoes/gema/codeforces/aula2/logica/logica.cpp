#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int conjunto_numeros[n];;

    if (n <= 1 || n >= 100000)
    {
        return 0;
    }
    

    for (int i = 0; i < n; i++)
    {
        int numeros;
        cin >> numeros;
        if (numeros > 100 || numeros < -100 || numeros == 0)
        {
            return 0;
        }
        
        conjunto_numeros[i] = numeros;
    }
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        if (conjunto_numeros[i] % 2 == 0 )
        {
            soma++;
        }
    }
    cout << soma;
    
   
}