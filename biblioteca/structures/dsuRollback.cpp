#include <bits/stdc++.h>
using namespace std;

struct DSU_Rollback {
    vector<int> par, sz;
    vector<pair<int, int>> history; 
    int components;

    DSU_Rollback(int n) {
        par.resize(n + 1);
        sz.assign(n + 1, 1);
        components = n;
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        while (u != par[u]) {
            u = par[u];
        }
        return u;
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        
        if (u == v) return false;

        if (sz[u] > sz[v]) swap(u, v);

        history.push_back({u, v});

        par[u] = v;
        sz[v] += sz[u];
        components--;
        
        return true;
    }

    int time() {
        return history.size();
    }

    void rollback(int t) {
        while (history.size() > t) {
            int u = history.back().first;
            int v = history.back().second;
            history.pop_back();

            sz[v] -= sz[u];
            par[u] = u;
            components++;
        }
    }
};
