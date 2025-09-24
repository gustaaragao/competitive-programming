#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

#define ff first
#define ss second
#define MAXN 200005

const int INF = 0x3f3f3f3f3f3f3f3fll;

struct node {
    int max_l, min_r;
};
int n, q;
pair<int, int> v[MAXN]; node seg[4*MAXN];
node single(pair<int, int> x) {
    return {x.ff, x.ss};
}
node neutral() {
    return {-INF, INF};
}
node merge(node a, node b) {
    return {max(a.max_l, b.max_l), min(a.min_r, b.min_r)};
}
node build(int p=1, int l=0, int r=n-1) {
    if (l == r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
node qry(int a, int b, int p=1, int l=0, int r=n-1) {
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
node upd(int i, pair<int, int> x, int p=1, int l=0, int r=n-1) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = single(x);
    int m = (l+r)/2;
    return seg[p] = merge(upd(i, x, 2*p, l, m), upd(i, x, 2*p+1, m+1, r));
}
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin>> v[i].ff >> v[i].ss;
    }
    build();
    while (q--) {
        char op; cin >> op;
        if (op == 'C') {
            int i, l, r; cin >> i >> l >> r;
            i--,
            v[i].ff = l; v[i].ss = r;
            upd(i, v[i]);
        } else { // op == '?'
            int a, b; cin >> a >> b;
            a--; b--;
            node ans = qry(a, b);
            cout << max(0LL, ans.min_r - ans.max_l + 1) << endl;
        }
    }
}