// Raphael Leveque 12542522
// main.cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> construindoGrafo(int n, double p);
void displayGrafo(vector<vector<bool>> grafo);
void lendoInput(int &n, double &p);

// Essa função foi colocada em cima da main porque é a função pedida no exercício
vector<vector<bool>> construindoGrafo(int n, double p) {
    vector<vector<bool>> grafo(n, vector<bool>(n));
    double xi = rand() / static_cast<double>(RAND_MAX);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            xi = rand() / static_cast<double>(RAND_MAX);
            if (xi > p) {
                grafo[i][j] = grafo[j][i] = 1;
            }
        }
    }
    return grafo;
}


int main() {
    cout << "Digite o número de vértices e a probabilidade de uma conexão existir entre 2 vértices" << endl;
    int n = 0;
    double p = 0;
    lendoInput(n, p);

    srand((unsigned int)time(NULL));
    displayGrafo(construindoGrafo(n, p));
}


void displayGrafo(vector<vector<bool>> grafo) {
    for (int i = 0; i < grafo.size(); i++) {
        for (int j = 0; j < grafo.size(); j++) {
            cout << setw(2) << grafo[i][j] << " ";
        }
        cout << endl;
    }
}


void lendoInput(int &n, double &p) {
    cin >> n;
    cin >> p;
    while (!(p > 0 && p < 1)) {
        cout << "Digite novamente a probabilidade (0, 1)" << endl;
        cin >> p;
    }
}
