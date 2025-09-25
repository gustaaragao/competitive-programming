#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define MAXN 100005
const int INF = 0x3f3f3f3f3f3f3f3fll;
struct node {
    int sum, pref, suff, ans;
};
int n, m, v[MAXN];
node seg[4*MAXN];
node single(int x) {
    node res;
    res.sum = x;
    res.pref = res.suff = res.ans = max(0LL, x);
    return res;
}
node neutral() {
    return {-INF, -INF, -INF, -INF};
}
node merge(node a, node b) {
    node res;
    res.sum = a.sum + b.sum;
    res.pref = max(a.pref, a.sum + b.pref);
    res.suff = max(b.suff, b.sum + a.suff);
    // ans = max(seg1, seg2, pref1 + suff2)
    res.ans = max(max(a.ans, b.ans), a.suff + b.pref);
    return res;
}
node build(int p=1, int l=0, int r=n-1) { // O(n)
    if (l == r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
node qry(int a, int b, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
node upd(int i, int x, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = single(x);
    int m = (l+r)/2;
    return seg[p] = merge(upd(i, x, 2*p, l, m), upd(i, x, 2*p+1, m+1, r));
}

signed main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];
    build();
    cout << qry(0, n-1).ans << endl;
    while (m--) {
        int i, x; cin >> i >> x;
        upd(i, x);
        cout << qry(0, n-1).ans << endl;
    }
}