#include<bits/stdc++.h>
using namespace std;
 
class Graph {
public:
    int V;
    vector<int> colors;    
    vector<list<int>> adj;    
    Graph(int V);   
    void addEdge(int v, int w);   

    friend ostream &operator<<(ostream &os, const Graph &g) {
        for (int i = 0; i < g.V; i++) {
            os << to_string(i) << ": ";
            string tmp;
            auto it = g.adj[i].begin();
            while (it != g.adj[i].end()) {
                os << to_string(*it) << " ";
                it++;
            }
            os << endl;
        }
        return os;
    }
};

int readingHeader() {
    string line;
    getline(cin, line);
    stringstream ss;    
    ss << line;
  
    string temp;
    int found;
    while (!ss.eof()) {
        ss >> temp;
        if (stringstream(temp) >> found)
            break;
        temp = "";
    }
    cin.ignore(256, '\n');
    return found;
}

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V + 1);
    colors.resize(V + 1);
    fill(colors.begin(), colors.end(), -1);
}
 
void Graph::addEdge(int v, int w) {
    bool encontrou_w = false;
    auto it = adj[v].begin();
    while (it != adj[v].end()) {
        if (*it == w) {
            encontrou_w = true;
            break;
        }
        it++;
    }
    if (!encontrou_w)
        adj[v].push_back(w);

    bool encontrou_v = false;
    it = adj[w].begin();
    while (it != adj[w].end()) {
        if (*it == v) {
            encontrou_v = true;
            break;
        }
        it++;
    }
    if (!encontrou_v)
        adj[w].push_back(v);
    
}

int main() {

    int vertices = readingHeader();
    Graph g(vertices);
    int x, y;
    while (cin >> x >> y) {
        g.addEdge(x, y);
    }

    vector<int> vertexGroup = {1,2,4,8,9,10,12,13,14};
    for(long unsigned int i = 0; i < vertexGroup.size(); i++) {
        vertexGroup = {1,2,4,8,9,10,12,13,14};
        Graph copy = g;
        bool equalColors = true;
        vector<int> vertexCopy(vertexGroup);
        auto it = std::find(vertexCopy.begin(),vertexCopy.end(),vertexGroup[i]);
        if (it != vertexCopy.end()) {
            vertexCopy.erase(it);
        }

        for (long unsigned int j = 0; j < vertexCopy.size(); j++) {
            for (long unsigned int k = j + 1; k < vertexCopy.size(); k++) {
                list<int>::iterator findIter = find(copy.adj[vertexCopy[k]].begin(), copy.adj[vertexCopy[k]].end(), vertexCopy[j]);
                bool encontrou = findIter != copy.adj[vertexCopy[k]].end();
                if (encontrou) {
                    equalColors = false;
                    break;
                }
            }
        }
        if (equalColors) {
            cout << (vertexGroup[i]) << endl;
            return 0;
        }
    }
    return 0;
}