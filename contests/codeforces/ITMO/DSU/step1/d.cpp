#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MAXN = 5e4 + 5;

int n, m, k, parent[MAXN], sz[MAXN];

void build() {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int i) {
    return parent[i] = (parent[i] == i ? i : find(parent[i])); 
}

void uni(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k;
    build();
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        uni(u , v);
    }
    for (int i = 0; i < k; i++) {
        string op; cin >> op;
        int u, v; cin >> u >> v; u--, v--;
        if (op == "ask") {
            cout << (find(u) == find(v) ? "YES" : "NO") << endl; 
        } else {
            cout << "?" << endl;
        }
    }
}