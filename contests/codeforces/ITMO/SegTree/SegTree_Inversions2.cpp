#include <bits/stdc++.h>
using namespace std; 
#define endl '\n'
#define MAXN 100000
int v[MAXN], seg[4*MAXN];
int single(int x) {return x;}
int neutral() {return 0;}
int merge(int a, int b) {return a +b;}
int build(int p, int l, int r) {
    if (l == r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
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
// find_kth é 1-INDEXED -> O(log(n)) -> Busca da DIREITA para ESQUERDA
int find_kth(int k, int p, int l, int r) {
    if (k > seg[p]) return -1;
    if (l == r) return l;
    int m = (l + r) / 2;
    if (seg[p*2+1] >= k)
        return find_kth(k, p*2+1, m+1, r);
    else
        return find_kth(k - seg[p*2+1], p*2, l, m);
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    fill(v, v + MAXN, 1);
    build(1, 0, n - 1); // SegTree [1, 1, 1, ...]
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> p(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        int k = v[i] + 1;
        int pos = find_kth(k, 1, 0, n - 1);
        p[i] = pos + 1;
        upd(pos, 0, 1, 0, n-1);
    }
    for (auto x : p) cout << x << " ";
    cout << endl;
}