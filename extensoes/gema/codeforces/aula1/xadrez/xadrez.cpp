#include <iostream>
using namespace std;

int main(){
    int n, m, multiplicacao;

    cin >> n;
    cin >> m;

    multiplicacao = n * m;

    if (multiplicacao % 2 == 0)
    {
        cout << (multiplicacao)/2;
    }
    else {
        cout << (multiplicacao / 2) + 1;
    }
    
}