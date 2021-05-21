#include <iostream>
using namespace std;

int main(){
    int x, y, p;

    cin >> p;

    if (p == 2)
    {
        cout << "0";
    }

    if (p != 2)
    {
        y = p / 2;
        x = y + 1;

        cout << "1" << endl;
        cout << x;
        cout << " ";
        cout << y;
    }
    
    

}