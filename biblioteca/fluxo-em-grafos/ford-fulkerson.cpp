#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int capacity[MAX][MAX];
vector<int> adj[MAX];
int parent[MAX];

bool dfs(int s, int t, int n, vector<bool>& visited) {
    if (s == t) return true;
    visited[s] = true;
    for (int v : adj[s]) {
        if (!visited[v] && capacity[s][v] > 0) {
            parent[v] = s;
            if (dfs(v, t, n, visited))
                return true;
        }
    }
    return false;
}

int ford_fulkerson(int s, int t, int n) {
    int max_flow = 0;
    while (true) {
        vector<bool> visited(n, false);
        memset(parent, -1, sizeof(parent));
        if (!dfs(s, t, n, visited)) break;

        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, capacity[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= path_flow;
            capacity[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}