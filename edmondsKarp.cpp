#include <bits/stdc++.h>
using namespace std;

struct EdmondsKarp {
    struct Edge {
        int to;
        long long cap, flow;
        int rev;
    };

    int n;
    vector<vector<Edge>> adj;
    vector<int> parentNode, parentEdgeIndex;

    EdmondsKarp(int n) : n(n), adj(n), parentNode(n), parentEdgeIndex(n) {}

    // Adiciona uma aresta do nó 'u' para o nó 'v' com capacidade 'cap'
    // Se directed = false, cria uma aresta bidirecional (ida e volta com mesma capacidade)
    void addEdge(int u, int v, long long cap, bool directed = true) {
        adj[u].push_back({v, cap, 0, (int)adj[v].size()});
        adj[v].push_back({u, directed ? 0 : cap, 0, (int)adj[u].size() - 1});
    }

    long long bfs(int s, int t) {
        fill(parentNode.begin(), parentNode.end(), -1);
        parentNode[s] = -2;
        queue<pair<int, long long>> q;
        q.push({s, 1e18});
        while (!q.empty()) {
            int cur = q.front().first;
            long long flow = q.front().second;
            q.pop();

            for (int i = 0; i < adj[cur].size(); i++) {
                Edge &e = adj[cur][i];
                if (parentNode[e.to] == -1 && e.cap - e.flow > 0) {
                    parentNode[e.to] = cur;
                    parentEdgeIndex[e.to] = i;
                    long long new_flow = min(flow, e.cap - e.flow);
                    
                    if (e.to == t) return new_flow;
                    q.push({e.to, new_flow});
                }
            }
        }
        return 0;
    }

    long long maxFlow(int s, int t) {
        long long flow = 0, new_flow;
        while ((new_flow = bfs(s, t))) {
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parentNode[cur];
                int edgeIdx = parentEdgeIndex[cur];
                
                adj[prev][edgeIdx].flow += new_flow;
                int revIdx = adj[prev][edgeIdx].rev;
                adj[cur][revIdx].flow -= new_flow;
                
                cur = prev;
            }
        }
        return flow;
    }
};
