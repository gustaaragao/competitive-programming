#include <bits/stdc++.h>
using namespace std; 
#define endl '\n'
#define MAXN 100005
const int INF = 0x3f3f3f3f;
int n, m, v[MAXN], seg[4*MAXN];

int single(int x) {return x;}
int neutral() {return INF;}
int merge(int a, int b) {return min(a, b);}

int build(int p=1, int l=0, int r=n-1) {
    if (l==r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
int qry(int a, int b, int p=1, int l=0, int r=n-1) {
    if (b<l or a>r) return neutral();
    if (a<=l and r<=b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
int upd(int i, int x, int p=1, int l=0, int r=n-1) {
    if (i<l or r<i) return seg[p];
    if (l==r) return seg[p] = single(x);
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
        } else {
            int a, b; cin >> a >> b;
            cout << qry(a, b-1) << endl;
        }
    }
}