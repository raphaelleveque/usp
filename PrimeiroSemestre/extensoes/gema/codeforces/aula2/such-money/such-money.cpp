#include <iostream>
using namespace std;

int main()
{
    int n, vi[100005];
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cin >> vi[i];
    }

    int maximo = vi[0], minimo = vi[0];

    for (int i = 0; i < n; i++)
    {
        if (vi[i] >= maximo)
        {
            maximo = vi[i];
        }
        else if (vi[i] <= minimo)
        {
            minimo = vi[i];
        }
        
    }
    cout << maximo - minimo ;

}


