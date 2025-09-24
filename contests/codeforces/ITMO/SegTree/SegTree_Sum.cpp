#include <bits/stdc++.h>
using namespace std; 
#define endl '\n'
#define int long long int
#define MAXN 100005
int a[MAXN], seg[4*MAXN], n, m;
int build(int p, int l, int r) {
    if (l == r) return seg[p] = a[l];
    int m = (l+r)/2;
    return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
}
int qry(int a, int b, int p, int l, int r) {
    if (b < l or a > r) return 0;
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return qry(a, b, 2*p, l, m) + qry(a, b, 2*p+1, m+1, r);
}
int upd(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l+r)/2;
    return seg[p] = upd(i, x, 2*p, l, m) + upd(i, x, 2*p+1, m+1, r);
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n-1);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i, x; cin >> i >> x;
            upd(i, x, 1, 0, n - 1);
        } else {
            int a, b; cin >> a >> b;
            cout << qry(a, b-1, 1, 0, n - 1) << endl;
        }
    }
}