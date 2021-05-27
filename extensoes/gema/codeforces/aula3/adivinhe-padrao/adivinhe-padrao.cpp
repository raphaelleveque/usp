#include <bits/stdc++.h>
using namespace std;

int main()
{
    int linhas, colunas;
    cin >> linhas >> colunas;
    int matriz[linhas][colunas];
    vector<bool> padrao(colunas, true);

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            int numero;
            cin >> numero;
            matriz[i][j] = numero;
        }
    }
    
    for (int i = 1; i <= colunas; i++)
    {
        for (int j = 1; j < linhas; j++)
        {
            if (matriz[1][i-1] > matriz[0][i-1])
            {
                if (matriz[j][i-1] <= matriz[j-1][i-1])
                {
                    padrao[i-1] = false;
                    break;
                }
            }
            else if (matriz[1][i-1] < matriz[0][i-1])
            {
                if (matriz[j][i-1] >= matriz[j-1][i-1])
                {
                    padrao[i-1] = false;
                    break;
                }
            }
            else if (matriz[1][i-1] == matriz[0][i-1])
            {
                if (matriz[j][i-1] != matriz[j-1][i-1])
                {
                    padrao[i-1] = false;
                    break;
                }
            }
            
                
        }
        
    }
    
    for (int i = 0; i < colunas; i++)
    {
        if (padrao[i] == true)
        {
            cout << "S" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
        
    }
    


}