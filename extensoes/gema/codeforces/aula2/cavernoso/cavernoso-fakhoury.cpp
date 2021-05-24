#include <bits/stdc++.h>
using namespace std;

int frequencia[1005];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string pipeline;
        cin >> pipeline;
        int tamanho = pipeline.size();
        frequencia[tamanho]++;
        // isso fará o seguinte: se o tamanho da string for de 8 caracteres, o vetor frequencia somará 1 na posição 8 
    }
    // agora só precisamos saber qual a posição do maior número desse vetor
    int answer = 0;

    for (int i = 0; i < 1000; i++)
    {
        if (frequencia[i] > frequencia[answer])
        {
            answer = i;
        }
    }  
    cout << answer << endl;
}