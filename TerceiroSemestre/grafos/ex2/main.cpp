#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
protected:
    const int vertices;
    vector<vector<bool>> graph;

public:
    Graph(int vertices) : vertices(vertices) {
        this->graph.resize(vertices);
        for (int i = 0; i < vertices; i++) {
            this->graph[i].resize(vertices);
        }
    }

    void add_edge(pair<int, int> edge) {
        this->graph[edge.first][edge.second] = this->graph[edge.second][edge.first] = true;
    }

    vector<int> adjacents(int v) {
        vector<int> adjacents;
        for (int i = 0; i < this->vertices; i++) {
            if (this->graph[v][i])
                adjacents.push_back(i);
        }
        return adjacents;
    }

    int get_vertices() {
        return this->vertices;
    }

    friend ostream &operator<<(ostream &os, const Graph &g) {
        for (int i = 0; i < g.vertices; i++) {
            string tmp;
            for (int j = 0; j < g.vertices; j++) {
                os << to_string(g.graph[i][j]) << " ";
            }
            os << endl;
        }
        return os;
    }
};

class BFS {
private:
    vector<bool> marked;
    vector<int> distance;

public:
    BFS(Graph g) {
        marked.resize(g.get_vertices(), false);
        distance.resize(g.get_vertices(), -1);
    }

    void bfs(Graph g, int source) {
        fill(marked.begin(), marked.end(), false);
        fill(distance.begin(), distance.end(), -1);

        queue<int> q;
        q.push(source);
        marked[source] = true;
        distance[source] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int w : g.adjacents(v)) {
                if (!marked[w]) {
                    q.push(w);
                    marked[w] = true;
                    distance[w] = distance[v] + 1;
                }
            }
        }
    }

    void printDistance(Graph g) {
        for (int j = 0; j < g.get_vertices(); j++) {
            bfs(g, j);

            for (int i = 0; i < g.get_vertices(); i++) {
                cout << distance[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    string line;
    getline(cin, line);
    int vertices = (line[10] - '0');
    scanf("%*[^\n]");

    Graph g(vertices);
    int x, y;
    while (cin >> x >> y) {
        g.add_edge(make_pair(x - 1, y - 1));
    }

    BFS bfs(g);
    bfs.printDistance(g);

    return 0;
}