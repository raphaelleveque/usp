#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, frequencia[1005];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string pipeline;
        cin >> pipeline;
        int tamanho = pipeline.size();
        frequencia[tamanho]++;
    }
    cout << max_element(frequencia, frequencia + 1000);

}