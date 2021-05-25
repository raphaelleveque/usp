#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, contador = 0;
    cin >> n >> k;
    n = n - 1;

    if (n < 2 && k > 2)
    {
        cout << "0";
        return 0;
    }
   

    switch (k)
    {
    case 1:
        cout << "1";
        return 0;

    case 2:
        while (n % 4 != 1) { n--; }
        break;

    case 4:
       while (n % 4 != 2) { n--; }
        break;

    case 8:
        while (n % 4 != 3) { n--; }
        break;
    
    case 6:
        while (n % 4 != 0) { n--; }
        break;
    
    default:
        cout << "0";
        return 0;
    }
    

    for (int i = n; i > 0; i-= 4)
    {
        contador++;
    }
    cout << contador ;

    return 0;
}