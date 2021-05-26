#include <bits/stdc++.h>
using namespace std;

int main()
{
    int linha, coluna;
    cin >> linha >> coluna;
    int matriz[linha][coluna], zero[2];

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                zero[0] = i;
                zero[1] = j;
            }
            
            matriz[i][j] = x;
        }
        
    }
    
    cout << zero[0] << " " << zero[1];

}