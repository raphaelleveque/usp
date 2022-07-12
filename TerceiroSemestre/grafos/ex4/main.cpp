#include<bits/stdc++.h> 
using namespace std;
 
class Graph {
    int V;    
    // adj[0] -> first = vertex, second = weight
    vector<vector<pair<int, int>>> adj;    
    int Graph::minDistance(vector<int> dist, vector<bool> sptSet);
public:
    Graph(int V);   
    void addEdge(int v, int w, int weight);   
    vector<int> Graph::dijkstra(int source);
    int get_vertices() {return this->V; }
};

void print_shortest_path(Graph g) {
    vector<vector<int>> distances;
    for (int i = 0; i < g.get_vertices(); i++) {
        distances[i] = g.dijkstra(i);
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

Graph::Graph(int V) : V(V) {
    adj.resize(V);
}
 
void Graph::addEdge(int v, int w, int weight) {
    adj[v].push_back(make_pair(w, weight)); 
}
 
int Graph::minDistance(vector<int> dist, vector<bool> shortest_path_tree)
{
   
    // Initialize min value
    int min = INT_MAX;
    int min_index;
 
    for (int v = 0; v < V; v++)
        if (shortest_path_tree[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}


vector<int> Graph::dijkstra(int source)
{
    vector<int> distance(this->V, INT_MAX);
    vector<bool> shortest_path_tree(this->V, false);
 
    distance[source] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(distance, shortest_path_tree);
 
        // Mark the picked vertex as processed
        shortest_path_tree[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (auto i : adj[u])
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!shortest_path_tree[v] && distance[u] != INT_MAX
                && (distance[u] + i.second < distance[v]))
                distance[v] = distance[u] + adj[u][v];
    }
    return distance;
} 



vector<int> Graph::dijkstra(int source) {
    vector<int> distance(this->V, INT_MAX);
    vector<int> previous_vertex(this->V, -1);
    // univisited nodes -> distance, vertex
    priority_queue<pair<int, int>> unvisited_nodes;

    unvisited_nodes.push(make_pair(0, source));
    distance[source] = 0;

    while (!unvisited_nodes.empty()) {
        for (const auto [vertex, weight] : this->adj[unvisited_nodes.top().second]) {
            if (distance[source] + weight < distance[vertex]) {
                int dist = distance[source] + weight;
                unvisited_nodes.push(make_pair(dist, vertex));
            }
        }
    }

}