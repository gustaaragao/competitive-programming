#include <bits/stdc++.h>
using namespace std; 
#define endl '\n'
#define ff first
#define ss second
typedef pair<int, int> pi;
const int INF = 0x3f3f3f3f;

#define MAXN 100005
int n, m, v[MAXN];
pi seg[4*MAXN]; // {min, #min}
pi single(int x) {return {x, 1};}
pi neutral() {return {INF, 0};}
pi merge(pi a, pi b) {
    if (a.ff < b.ff) return a;
    if (b.ff < a.ff) return b;
    return {a.ff, a.ss + b.ss};
}
pi build(int p=1, int l=0, int r=n-1) { // O(n)
    if (l == r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
pi qry(int a, int b, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
pi upd(int i, int x, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = single(x);
    int m = (l+r)/2;
    return seg[p] = merge(upd(i, x, 2*p, l, m), upd(i, x, 2*p+1, m+1, r));
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];
    build();
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i, x; cin >> i >> x;
            upd(i, x);
        } else { // op == 2
            int a, b; cin >> a >> b;
            auto [min, cnt] = qry(a, b-1);
            cout << min << " " << cnt << endl;
        }
    }
}