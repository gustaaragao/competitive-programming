#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int capacity[MAX][MAX];
vector<int> adj[MAX];
int parent[MAX];

bool bfs(int source, int sink, int n) {
    bool visited[MAX];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v] && capacity[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[sink];
}

int edmonds_karp(int source, int sink, int n) {
    int max_flow = 0;
    while (bfs(source, sink, n)) {
        int path_flow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, capacity[u][v]);
        }
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= path_flow;
            capacity[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
