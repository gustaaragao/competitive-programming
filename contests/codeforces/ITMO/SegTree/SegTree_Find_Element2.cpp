#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000
const int INF = 0x3f3f3f3f3f3f3f3fll;
int v[MAXN], seg[4*MAXN];

int single(int x) {return x;}
int neutral() {return -INF;}
int merge(int a, int b) {return max(a, b);}

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
// primeira posição >= x em [a, b] (ou -1, caso não exista)
int first_above(int x, int a, int b, int p, int l, int r) { // O(log(n))
    if (b < l or r < a or seg[p] < x) return -1;
	if (l == r) return l;
	int m = (l+r)/2;
	int left = first_above(x, a, b, 2*p, l, m);
	if (left != -1) return left;
	return first_above(x, a, b, 2*p+1, m+1, r);
}
signed main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n -1);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i, x; cin >> i >> x;
            upd(i, x, 1, 0, n-1); 
        } else {
            int x, a; cin >> x >> a;
            cout << first_above(x, a, n - 1, 1, 0, n-1) << endl;
        }
    }
}