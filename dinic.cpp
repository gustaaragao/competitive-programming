#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge {
        int to;
        long long cap, flow;
        int rev;
    };

    int n;
    vector<vector<Edge>> adj;
    vector<int> level;
    vector<int> ptr;

    Dinic(int n) : n(n), adj(n), level(n), ptr(n) {}

    void addEdge(int u, int v, long long cap, bool directed = true) {
        adj[u].push_back({v, cap, 0, (int)adj[v].size()});
        adj[v].push_back({u, directed ? 0 : cap, 0, (int)adj[u].size() - 1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& e : adj[v]) {
                if (e.cap - e.flow > 0 && level[e.to] == -1) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, int t, long long pushed) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;

        for (int& cid = ptr[v]; cid < adj[v].size(); ++cid) {
            auto& e = adj[v][cid];
            int tr = e.to;
            if (level[v] + 1 != level[tr] || e.cap - e.flow == 0) continue;
            
            long long push = dfs(tr, t, min(pushed, e.cap - e.flow));
            if (push == 0) continue;
            e.flow += push;
            adj[tr][e.rev].flow -= push;
            return push;
        }
        return 0;
    }

    long long maxFlow(int s, int t) {
        long long flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, t, 1e18)) {
                flow += pushed;
            }
        }
        return flow;
    }
};
