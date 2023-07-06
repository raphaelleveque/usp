#include <bits/stdc++.h>
using namespace std;

template <typename... T>
void read(T &...args) { ((cin >> args), ...); }

template <typename... T>
void write(T &&...args) { ((cout << args << " "), ...); }

template <typename... T>
void writeln(T &&...args) {
    ((cout << args << " "), ...);
    cout << '\n';
}

void print() {}

template <typename T, typename... Args>
void print(T a, Args... args) {
    cerr << a << "=" << a << ", ";
    print(args...);
}

#define ll long long
#define int long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector

const ll inf = 1LL << 62;
const double ep = 0.0000001;
const double pi = acos(-1.0);
const ll md = 1000000007;

vc<tiii> adj[505];
int xpow(int x, unsigned int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) {
            res = (res * x);
        }
        y = y >> 1;
        x = (x * x);
    }
    return res;
}
int d, n;
bool vis[505];

int dfs(int s, int f) {
    if (s == n)
        return f;
    vis[s] = 1;
    for (auto &[i, w, j] : adj[s]) {
        if (w >= d && !vis[i]) {
            int b = dfs(i, min(f, w));
            if (b > 0) {
                w -= b;
                get<1>(adj[i][j]) += b;
                return b;
            }
        }
    }
    return 0;
}

void solve() {
    int m;
    read(n, m);
    int mx = 0;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        read(x, y, w);
        mx = max(mx, w);
        int j1 = adj[x].size();
        int j2 = adj[y].size();
        adj[x].push_back({y, w, j2});
        adj[y].push_back({x, 0, j1});
    }
    d = xpow(2, (int)log2(mx));
    int ans = 0;
    while (d > 0) {
        while (1) {
            memset(vis, 0, sizeof vis);
            ll f = dfs(1, inf);
            ans += f;
            if (f == 0)
                break;
        }
        d >>= 1;
    }
    write(ans);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}