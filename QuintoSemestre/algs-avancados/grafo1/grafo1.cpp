#include <bits/stdc++.h>
using namespace std;
#define int long long
template <typename... T>
void see(T &...args) { ((cin >> args), ...); }
template <typename... T>
void put(T &&...args) { ((cout << args << " "), ...); }
template <typename... T>
void putl(T &&...args) {
    ((cout << args << " "), ...);
    cout << '\n';
}

const int N = 505;
int dis[N][N];
void solve() {
    int n, m, q;
    see(n, m, q);
    int M = 1000000000000;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
            dis[i][j] = M;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        see(u, v, w);
        dis[u][u] = 0, dis[v][v] = 0;
        dis[u][v] = min(dis[u][v], w), dis[v][u] = min(dis[u][v], w);
    }
    for (int k = 1; k < n + 1; k++) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        see(a, b);
        if (dis[a][b] < M)
            putl(dis[a][b]);
        else
            putl(-1);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    while (t--) {
        solve();
    }
}