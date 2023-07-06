#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct edge {
    int v, capacity, rev;
};

vector<edge> connect[51];

void add_edge(int u, int v, int capacity) {
    connect[u].push_back(edge{v, capacity, static_cast<int>(connect[v].size())});
    connect[v].push_back(edge{u, 0, static_cast<int>(connect[u].size() - 1)});
}

int level[51];
int iter[51];
bool V[51];
bool T[51][51];
int n, m;

void BFS(int s) {
    memset(level, -1, sizeof(level));
    queue<int> Q;
    level[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < static_cast<int>(connect[u].size()); i++) {
            edge &e = connect[u][i];
            if (e.capacity > 0 && level[e.v] < 0) {
                level[e.v] = level[u] + 1;
                Q.push(e.v);
            }
        }
    }
}

int DFS(int u, int t, int flow) {
    if (u == t)
        return flow;
    for (int &i = iter[u]; i < static_cast<int>(connect[u].size()); i++) {
        edge &e = connect[u][i];
        if (e.capacity > 0 && level[u] < level[e.v]) {
            int d = DFS(e.v, t, min(flow, e.capacity));
            if (d > 0) {
                e.capacity -= d;
                connect[e.v][e.rev].capacity += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (true) {
        BFS(s);
        if (level[t] < 0)
            return flow;
        memset(iter, 0, sizeof(iter));
        while (true) {
            int tmp = DFS(s, t, 2e9);
            if (tmp <= 0)
                break;
            flow += tmp;
        }
    }
}

void find(int s) {
    V[s] = true;
    for (int i = 0; i < static_cast<int>(connect[s].size()); i++) {
        edge &e = connect[s][i];
        if (!V[e.v] && e.capacity > 0)
            find(e.v);
    }
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; i++)
            connect[i].clear();
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add_edge(a, b, c);
            add_edge(b, a, c);
        }
        max_flow(1, 2);
        memset(V, false, sizeof(V));
        find(1);
        memset(T, false, sizeof(T));
        for (int i = 1; i <= n; i++) {
            if (V[i]) {
                for (int j = 0; j < static_cast<int>(connect[i].size()); j++) {
                    edge e = connect[i][j];
                    if (!

V[e.v] && !T[i][e.v]) {
                        printf("%d %d\n", i, e.v);
                        T[i][e.v] = T[e.v][i] = true;
                    }
                }
            }
        }
        putchar('\n');
    }
    return 0;
}