#include<bits/stdc++.h>
 
using namespace std;
 
class Graph {
    int V;    
    vector<list<int>> adj;    
    bool isCyclicUtil(int v, vector<bool> visited, vector<bool> recStack);  
public:
    Graph(int V);   
    void addEdge(int v, int w);   
    bool isCyclic();    
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

    if(g.isCyclic())
        cout << "S" << endl;
    else
        cout << "N" << endl;
    return 0;
}

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}
 
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); 
}
 
bool Graph::isCyclicUtil(int v, vector<bool> visited, vector<bool> recStack) {
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
 
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false; 
    return false;
}

bool Graph::isCyclic() {
    vector<bool> visited(V);
    vector<bool> recStack(V);
    for(int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
 
    for(int i = 0; i < V; i++)
        if ( !visited[i] && isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}