#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> caracteres;
    cin >> n;
    string pipe[n];

    for (int i = 0; i < n; i++)
    {
        cin >> pipe[i];
    }

    for (int i = 0; i < n; i++)
    {
        caracteres.push_back(pipe[i].length());
    }
    
    sort(caracteres.begin(), caracteres.end());
    
    for (int i = 0; i < n; i++)
    {
        cout << caracteres[i];
        cout << endl;
    }
    
}