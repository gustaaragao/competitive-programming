#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MAXN = 3e5 + 10;

struct Node {
    int size;
    int min;
    int max;
};

Node v[MAXN];
int n, m, parent[MAXN]; 

int find(int i) {
    return parent[i] = (parent[i] == i ? i : find(parent[i]));
}

void uni(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) {
        if (v[a].size < v[b].size) {
            swap(a, b);
        }
        parent[b] = a;
        v[a].size += v[b].size;
        v[a].max = max(v[a].max, v[b].max);
        v[a].min = min(v[a].min, v[b].min);
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        v[i] = {1, i, i};
    }
    while (m--) {
        string op; cin >> op;
        if (op == "get") {
            int x; cin >> x; x--;
            Node ret = v[find(x)];
            cout << ret.min + 1 << " " << ret.max + 1 << " " << ret.size << endl;
        } else {
            int u, v; cin >> u >> v; u--, v--;
            uni(u, v);
        }
    }
}
