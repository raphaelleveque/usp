#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int bola1x, bola1y, bola2x, bola2y;

    cin >> n;
    cin >> bola1x >> bola1y;
    cin >> bola2x >> bola2y;

    int divisoria = n / 2;

    if (bola1x < divisoria && bola1y < divisoria )
    {
        if (bola2x < divisoria && bola2y < divisoria )
        {
            cout << "N";
        }
        else
        {
            cout << "S";
        }
        
    }
    else if (bola1x < divisoria && bola1y > divisoria)
    {
        if (bola2x < divisoria && bola2y > divisoria )
        {
            cout << "N";
        }
        else
        {
            cout << "S";
        }
    }
    else if (bola1x > divisoria && bola1y > divisoria)
    {
        if (bola2x > divisoria && bola2y > divisoria )
        {
            cout << "N";
        }
        else
        {
            cout << "S";
        }
    }
    else if (bola1x > divisoria && bola1y < divisoria)
    {
        if (bola2x > divisoria && bola2y < divisoria )
        {
            cout << "N";
        }
        else
        {
            cout << "S";
        }
    }
    
    


    return 0;
}