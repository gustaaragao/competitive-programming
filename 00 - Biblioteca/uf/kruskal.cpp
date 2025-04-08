#include <bits/stdc++.h>
using namespace std; 

#include "union-find.cpp"

// Representa uma aresta
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

vector<Edge> kruskal(int n, vector<Edge>& edges) {
    UnionFind uf(n);
    vector<Edge> mst;  
    
    sort(edges.begin(), edges.end());

    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        if (uf.find(u) != uf.find(v)) {
            uf.unionSets(u, v);
            mst.push_back(edge);  
            if (mst.size() == n - 1) {
                break;
            }
        }
    }
    return mst;
}
