#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<vector<char>> grid;
    vector<vector<bool>> visited;
    string s;

    Graph(const vector<vector<char>> &grid, string s) : grid{grid}, s{s} {
        visited.reserve(grid.size());
        for (int i = 0; i < (int)grid.size(); i++)
            visited[i].reserve(grid[i].size());
    }

    // ixj to traverse grid
    // k to traverse string
    bool DFS(int i, int j, int k) {
        if (k == (int)s.size())
            return true;
        if (k == -1)
            return false;
        
        if (i >= (int)grid.size() || j >= (int)grid[i].size() || i < 0 || j < 0|| visited[i][j]) {
            return false;
        }
        
        if (grid[i][j] == s[k]) {
            k++;
            visited[i][j] = true;
        } else {
            return false;
        }

        bool retFunc = DFS(i, j+1, k);
        if (retFunc) return true;
        else 
        
        retFunc = DFS(i, j-1, k);
        if (retFunc) return true;

        retFunc = DFS(i+1, j, k);
        if (retFunc) return true;

        retFunc = DFS(i-1, j, k);
        if (retFunc) return true;

        k = -1;
        visited[i][j] = false;
        return false;
    }

    void reset_vector() {
        for(int i = 0; i < (int)visited.size(); i++) {
            fill(visited[i].begin(), visited[i].end(), false);
        }
    }

};


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n);
    char tmp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            grid[i].push_back(tmp);
        }
    }
    int word_size;
    cin >> word_size;
    string s;
    cin >> s;

    Graph g(grid, s);
    int k;
    bool ret;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            k = 0;
            ret = false;
            if (g.grid[i][j] == s[0]) {
                g.reset_vector();
                ret = g.DFS(i, j, k);
            }
            if (ret == true) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}