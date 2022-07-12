#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;    
    vector<vector<int>> g;
    int minDistance(vector<int> dist, vector<bool> sptSet);
public:
    Graph(int V);   
    void addEdge(int v, int w, int weight);   
    vector<int> dijkstra(int source);
    int get_vertices() {return this->V; }
};

int Graph::minDistance(vector<int> dist, vector<bool> sptSet) {
   
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

vector<int> Graph::dijkstra(int source) {
    vector<int> distance(V, INT_MAX);
    vector<bool> sptSet(V, false);
 
    distance[source] = 0;
 
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(distance, sptSet);
 
        sptSet[u] = true;
 
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && g[u][v] && distance[u] != INT_MAX
                && distance[u] + g[u][v] < distance[v])
                distance[v] = distance[u] + g[u][v];
    }
    return distance;
}

Graph::Graph(int V){
    this->V = V;
    g.resize(V);
    for (int i = 0; i < V; i++)
        g[i].resize(V);
}
 
void Graph::addEdge(int v, int w, int weight) {
    g[v][w] = weight;
}
 

void print_shortest_path(Graph g) {
    vector<vector<int>> distances(g.get_vertices());
    for (int i = 0; i < g.get_vertices(); i++) {
        distances[i] = g.dijkstra(i);
    }
    int max = -1;
    for (int i; i < g.get_vertices(); i++) {
        auto it = max_element(begin(distances[i]), end(distances[i]));
        if (*it > max) 
            max = *it;
    }

    int digits = int(log10(max) + 1);

    for (int i = 0; i < g.get_vertices(); i++){
        for (int j = 0; j < g.get_vertices(); j++){
            cout << setw(digits) << distances[i][j] << (j == g.get_vertices() - 1 ? "" : " ");
        }
        cout << endl;
    }   
    
}

int readingHeader(ifstream &myfile) {
    string line;
    getline(myfile, line);
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
    myfile.ignore(256, '\n');
    return found;
}

int main() {
    string fileName;
    cin >> fileName;
    ifstream myfile;
    myfile.open(fileName);
    if (!myfile.is_open()) {
        exit(EXIT_FAILURE);
    }

    int vertices = readingHeader(myfile);
    Graph g(vertices);
    int v1, v2, weight;
    while (myfile >> v1 >> v2 >> weight) {
        g.addEdge(v1 - 1, v2 - 1, weight);
    }

    print_shortest_path(g);
}