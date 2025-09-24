#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int v[MAXN], seg[4*MAXN];

int single(int x) { return x; }
int neutral() { return 0; }
int merge(int a, int b) { return a+b; }

int build(int p, int l, int r) {
    if (l == r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
// qry -> retorna o número de 1s no range [a, b]
int qry(int a, int b, int p, int l, int r) {
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
int upd(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = single(x);
    int m = (l+r)/2;
    return seg[p] = merge(upd(i, x, 2*p, l, m), upd(i, x, 2*p+1, m+1, r));
}
// find_kth é 1-INDEXED -> O(log(n))
int find_kth(int k, int p, int l, int r) {
    if (k > seg[p]) return -1;
    if (l == r) return l;
    int m = (l + r) / 2;
    if (seg[p*2] >= k)
        return find_kth(k, p*2, l, m);
    else
        return find_kth(k - seg[p*2], p*2+1, m+1, r);
}
// Para adaptar esse problema para Kth Zero basta usar o operador "!"
signed main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n - 1);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i; cin >> i;
            v[i] = !v[i];
            upd(i, v[i], 1, 0, n-1);
        } else {
            int k; cin >> k;
            cout << find_kth(k+1, 1, 0, n-1) << endl;
        }
    }
}