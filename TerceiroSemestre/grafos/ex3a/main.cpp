#include "graph.hpp"
#include <bits/stdc++.h>
using namespace std;

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
    scanf("%*[^\n]");
    return found;
}

int main() {
    int vertices = readingHeader();
    Graph g(vertices);
    int x, y;
    while (cin >> x >> y) {
        g.addEdge(x - 1, y - 1);
    }

    g.connectedComponents();
    vector<int> ans = g.componentsSize();

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << endl;
    return 0;
}