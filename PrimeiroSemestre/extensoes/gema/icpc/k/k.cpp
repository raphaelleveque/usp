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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tMin, duration, nRef;
    cin >> tMin >> duration >> nRef;
    if (nRef <= 0) {
        if ((tMin <= duration)) {
            cout << 'Y' << endl;
        } else
            cout << 'N' << endl;
        return 0;
    }
    int tRef[nRef + 2];
    tRef[0] = 0;
    tRef[nRef + 1] = duration;

    for (int i = 1; i < nRef + 2; i++) {
        if (i != nRef + 1) {
            cin >> tRef[i];
        }

        if (tRef[i] - tRef[i - 1] >= tMin) {
            cout << 'Y' << endl;
            fflush(stdin);
            return 0;
        }
    }
    cout << 'N' << endl;

    return 0;
}