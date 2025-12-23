#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct dsu {
    vector<int> parent, size;
    dsu(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int i) {
        return parent[i] = (parent[i] == i) ? i : find(parent[i]);
    }
    void uni(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (size[a] > size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

signed main() {
    int n, m; cin >> n >> m;
    dsu d = dsu(n);
    for (int i = 0; i < m; i++) {
        string op; cin >> op;
        int u, v; cin >> u >> v; u--, v--;
        if (op == "union") {
            d.uni(u, v);
        } else { // op == "get"
            if (d.find(u) == d.find(v)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}