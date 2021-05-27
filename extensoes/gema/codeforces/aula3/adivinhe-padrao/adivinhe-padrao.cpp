#include <bits/stdc++.h>
using namespace std;

int main()
{
    int linhas, colunas;
    cin >> linhas >> colunas;
    int matriz[linhas][colunas];
    bool padrao[colunas] = {true};

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            int numero;
            cin >> numero;
            matriz[i][j] = numero;
        }
    }
    
    for (int i = 1; i < colunas; i++)
    {
        for (int j = 1; j < linhas; j++)
        {
            if (matriz[i-1][1] > matriz[i-1][0])
            {
                if (matriz[i][j] < matriz[i-1][j-1])
                {
                    padrao[i-1] = false;
                    break;
                }
            }
            if (matriz[i-1][1] < matriz[i-1][0])
            {
                if (matriz[i][j] > matriz[i-1][j-1])
                {
                    padrao[i-1] = false;
                    break;
                }
            }
            if (matriz[i-1][1] == matriz[i-1][0])
            {
                if (matriz[i][j] != matriz[i-1][j-1])
                {
                    padrao[i-1] = false;
                    break;
                }
            }
            
                
        }
        
    }
    
    for (int i = 0; i < colunas; i++)
    {
        if (padrao[colunas] == true)
        {
            cout << "S" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
        
    }
    


}