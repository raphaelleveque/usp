#include <bits/stdc++.h>
using namespace std;

int pt = 0;

int solve(int n, int m, vector<int>& primos) {
    if (m == 0)
        return 0;
    int i = 0;
    while (i < pt && primos[i] <= sqrt(m)) {
        if (m % primos[i] == 0) {
            int a = 0;
            while (m % primos[i] == 0) {
                a++;
                m /= primos[i];
            }
            int temp = n, b = 0;

            while (temp) {
                temp /= primos[i];
                b += temp;
            }
            if (b < a) return 0;
        }
        i++;
    }
    if (m > 1 && n < m)
        return 0;
    return 1;
}

int main() {
    int nprimos = 50000;
    vector<int> primos;
    vector<int> aux(nprimos);
    pt = 0;

    for (int i = 2; i < nprimos; i++) {
        if (aux[i] == 0) {
            primos.push_back(i);
            pt++;
            for (int j = 2 * i; j < nprimos; j += i) {
                aux[j] = 1;
            }
        }
    }
    int n, m;
    while (cin >> n >> m) {
        if (solve(n, m, primos)) {
            cout << m << " divides " << n << "!\n";
        } else {
            cout << m << " does not divide " << n << "!\n";
        }
    }
}