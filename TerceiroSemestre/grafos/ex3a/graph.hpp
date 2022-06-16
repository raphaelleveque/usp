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