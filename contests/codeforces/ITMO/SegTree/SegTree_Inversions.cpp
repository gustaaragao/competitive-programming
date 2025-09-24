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
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    memset(v, 0, sizeof(v));
    build(1, 0, n - 1); // SegTree vazia ([0, 0, 0, ...])
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        // Query [v[i], n] -> quantos números maiores que v[i] já foram vistos?
        int ans = qry(v[i]-1, n-1, 1, 0, n-1);
        cout << ans << " ";
        // Update -> Marca que visitou o valor v[i]
        upd(v[i]-1, 1, 1, 0, n - 1);
    }
    cout << endl;
}