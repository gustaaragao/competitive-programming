#include <bits/stdc++.h>
using namespace std; 

#define endl '\n'
#define int long long int

#define MAXN 100005

int n, q, v[MAXN], seg[4*MAXN];
int single(int x) {
    return (1LL << (x-1));
}
int neutral() {
    return 0;
}
int merge(int a, int b) {
    return a | b;
}
int build(int p=1, int l=0, int r=n-1) { // O(n)
    if (l == r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
int qry(int a, int b, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
int upd(int i, int x, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = single(x);
    int m = (l+r)/2;
    return seg[p] = merge(upd(i, x, 2*p, l, m), upd(i, x, 2*p+1, m+1, r));
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> v[i];
    build();
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int a, b; cin >> a >> b;
            a--, b--;
            bitset<64> ans(qry(a, b));
            cout << ans.count() << endl;
        } else {
            int i, x; cin >> i >> x;
            i--;
            upd(i, x);
        }
    }
}
/*
Como o 1 <= v[i] <= 40, podemos guardar em um bitmask (long long int, ou seja, 64 bits)
se um número apareceu o não.

(1 << x) -> o número X apareceu no Segmento

(a | b)  -> unir os números que apareceram no Segmento A e B.
*/