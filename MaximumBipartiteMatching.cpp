#include <bits/stdc++.h>
using namespace std;

struct Kuhn {
    int n, m;
    vector<vector<int>> adj;
    vector<int> match; // match[i] guarda o vértice da ESQUERDA conectado ao vértice 'i' da DIREITA
    vector<bool> used; // Marca se o vértice da ESQUERDA já foi visitado na DFS atual

    Kuhn(int n, int m) : n(n), m(m), adj(n), match(m, -1), used(n, false) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool dfs(int v) {
        if (used[v]) return false;
        used[v] = true;
        for (int to : adj[v]) {
            if (match[to] == -1 || dfs(match[to])) {
                match[to] = v;
                return true;
            }
        }
        return false;
    }

    int maxMatching() {
        int matches = 0;
        vector<bool> used_left(n, false);
        for (int i = 0; i < n; ++i) {
            for (int to : adj[i]) {
                if (match[to] == -1) {
                    match[to] = i;
                    used_left[i] = true;
                    matches++;
                    break;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (used_left[i]) continue;
            fill(used.begin(), used.end(), false);
            if (dfs(i)) {
                matches++;
            }
        }
        
        return matches;
    }
};
