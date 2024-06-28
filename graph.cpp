#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph {
    public:
        map<int, bool> visited;
        map<int, list<int>> adj;

        void add_edge(int u, int v, int weight);

        void print_graph(int u, int v, int weight);

        void DFS(int u);
};

void Graph::add_edge(int u, int v, int weight) {
    adj[u].push_back(v);
}

void Graph::DFS(int u) {
    visited[u] = true;
    cout << u << " ";

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++) {
        if (!visited[*i]) {
            DFS(*i);
        }
    }
}

int main() {
    Graph g;
    g.add_edge(0, 1, 1);
    g.add_edge(0, 2, 1);
    g.add_edge(1, 2, 1);
    g.add_edge(2, 0, 1);
    g.add_edge(2, 3, 1);
    g.add_edge(3, 3, 1);

    g.DFS(2); // DFS starting at node 2

    return 0;
}