#include <bits/stdc++.h>
using namespace std;


class Graph {
private:
    void DFSUtil(int v);

    int total_vertices;
    int total_components;

    map<int, bool> visited;
    map<int, list<int> > adj;
    vector<int> id;

    // prints DFS traversal of the complete graph
    void DFS(int v, int component);
 
public:
    // constructor
    Graph(int vertices);

    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // find how many connected components there are
    int connectedComponents();

    // returns the size of each component
    vector<int> componentsSize();
};


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
    int x, y;
    while (myfile >> x >> y) {
        g.addEdge(x - 1, y - 1);
    }

    g.connectedComponents();
    vector<int> ans = g.componentsSize();

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << endl;
    return 0;
}


Graph::Graph(int vertices) {
    total_vertices = vertices;
    id.resize(vertices);
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v);
}
 
void Graph::DFSUtil(int v) {
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i);
}
 
// The function to do DFS traversal. It uses recursive
// DFSUtil()
void Graph::DFS(int v, int component) {
    // Mark the current node as visited and
    // print it
    visited[v] = true;

    // map the vertex to its id component
    id[v] = component;
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, component);
}

int Graph::connectedComponents() {
    int components = 0;

    for (int v = 0; v < total_vertices; v++) {  // run dfs for each not marked vertex
        if (!visited[v]) {
            DFS(v, components);
            components++;
        }
    }
    total_components = components;
    return components;
}

vector<int> Graph::componentsSize() {
    vector<int> ans;
    int component = 0;
    for (int i = 0; i < total_components; i++) {
        component = count(id.begin(), id.end(), i);
        ans.push_back(component);
    }
    sort(ans.rbegin(), ans.rend());
    return ans;
}