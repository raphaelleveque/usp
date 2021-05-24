#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, soma = 0;
    cin >> n;
    char caracteres[] = "abcdefghijklmnopqrstuvwxyz";
    char palindromo[n];

    for (int i = 0; i < n; i++)
    {
        cin >> palindromo[i];
    }
    


    if (n % 2 == 0)
    {
        for (int i = 0; i < n/2; i++)
        {
            for (int j = n; j > n/2; j--)
            {
                if (palindromo[i] != palindromo[j])
                {
                    soma++;
                }
                
            }
            
        }
    }
    else
    {
        for (int i = 0; i < (n-1)/2; i++)
        {
            for (int j = n-1; j > (n-1)/2; j--)
            {
                if (palindromo[i] != palindromo[j])
                {
                    soma++;
                }
                
            }
            
        }
    }
    cout << soma;

}