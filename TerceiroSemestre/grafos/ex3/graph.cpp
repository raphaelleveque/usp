#include "graph.hpp"
 
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