#include <bits/stdc++.h>
using namespace std; 

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAXN 100005

int n, m, v[MAXN];
int seg_pares[4*MAXN], seg_impares[4*MAXN];

int single(int x) {return x;}
int neutral() {return 0;}
int merge(int a, int b) { return a + b; }
int build_pares(int p=1, int l=0, int r=n-1) {
    if (l == r) {
        if (l % 2 == 0)
            return seg_pares[p] = single(v[l]);
        else
            return neutral();
    }
    int m = (l+r)/2;
    return seg_pares[p] = merge(build_pares(2*p, l, m), build_pares(2*p+1, m+1, r));
}
int build_impares(int p=1, int l=0, int r=n-1) {
    if (l == r) {
        if (l % 2 != 0)
            return seg_impares[p] = single(v[l]);
        else
            return neutral();
    }
    int m = (l+r)/2;
    return seg_impares[p] = merge(build_impares(2*p, l, m), build_impares(2*p+1, m+1, r));
}

int qry(int a, int b, int seg[], int p=1, int l=0, int r=n-1) {
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, seg, 2*p, l, m), qry(a, b, seg, 2*p+1, m+1, r));
}

int upd(int i, int x, int seg[], int p=1, int l=0, int r=n-1) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = single(x);
    int m = (l+r)/2;
    return seg[p] = merge(upd(i, x, seg, 2*p, l, m), upd(i, x, seg, 2*p+1, m+1, r));
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    build_pares(); build_impares();
    cin >> m;
    while (m--) {
        int op; cin >> op;
        if (op == 0) {
            int i, x; cin >> i >> x;
            i--;
            if (i % 2 == 0) upd(i, x, seg_pares);
            else upd(i, x, seg_impares);
        } else {
            int a, b; cin >> a >> b;
            a--, b--;
            int soma_pares = qry(a, b, seg_pares);
            int soma_impares = qry(a, b, seg_impares);
            if (a % 2 == 0) {
                cout << soma_pares - soma_impares << endl;
            } else {
                cout << soma_impares - soma_pares << endl;
            }
        }
    }
}
/*
Se l % 2 == 0, temos que v[l] - v[l+1] + v[l+2] - v[l+3] = SOMA_PARES - SOMA_IMPARES
Senão, temos que v[l] - v[l+1] + v[l+2] - v[l+3] = SOMA_IMPARES - SOMA_PARES
*/