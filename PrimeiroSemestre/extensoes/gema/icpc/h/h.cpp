#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

#define DBG(x) cout << "[" << #x << "]: " << x << '\n'
#define all(x) x.begin(), x.end()
#define mset(a, b) memset(a, b, sizeof(a))

using ll = long long;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;
const int MXN = 1e5 + 5;

typedef struct h {
    int num;
    int cor;
} H;

void merge(H nms[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    H vEsq[n1], vDir[n2];
    int k = esq;

    for (int i = 0; i < n1; i++, k++)
        vEsq[i] = nms[k];
    for (int i = 0; i < n2; i++, k++)
        vDir[i] = nms[k];

    int topoEsquerda = 0;
    int topoDireita = 0;
    k = esq;

    while (topoEsquerda < n1 && topoDireita < n2) {
        if (vEsq[topoEsquerda].num <= vDir[topoDireita].num) {
            nms[k] = vEsq[topoEsquerda];
            topoEsquerda++;
        } else {
            nms[k] = vDir[topoDireita];
            topoDireita++;
        }
        k++;
    }
    while (topoEsquerda < n1) {
        nms[k] = vEsq[topoEsquerda];
        topoEsquerda++;
        k++;
    }
    while (topoDireita < n2) {
        nms[k] = vDir[topoDireita];
        topoDireita++;
        k++;
    }
}

void mergeSort(H nms[], int esq, int dir) {
    if (esq >= dir)
        return;

    int meio = (int)((esq + dir) / 2.0);
    mergeSort(nms, esq, meio);
    mergeSort(nms, meio + 1, dir);

    merge(nms, esq, meio, dir);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    H nms[n];
    int cortmp[n];

    for (int i = 0; i < n; i++) {
        cin >> nms[i].num >> nms[i].cor;
        cortmp[i] = nms[i].cor;
    }
    mergeSort(nms, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (cortmp[i] != nms[i].cor) {
            cout << 'N' << endl;
            return 0;
        }
    }

    cout << 'Y' << endl;

    return 0;
}