#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int maximo = 1;
    int minimo = 1000000005;

    for (int i = 0; i < n; i++)
    {
        int vi;
        cin >> vi;

        if (vi >= maximo)
        {
            maximo = vi;
        }
        if (vi <= minimo)
        {
            minimo = vi;
        }
    }
    cout << maximo - minimo ;
}