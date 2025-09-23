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

#define MAXN 100000

int v[MAXN];
pi seg[4*MAXN]; // {min, #min}
pi combina(pi a, pi b) {
    if (a.ff < b.ff) return a;
    if (b.ff < a.ff) return b;
    return {a.ff, a.ss + b.ss};
}
pi build(int p, int l, int r) { // O(n)
    if (l == r) return seg[p] = {v[l], 1};
    int m = (l+r)/2;
    return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
}
pi qry(int a, int b, int p, int l, int r) { // O(log(n))
    if (b < l or a > r) return {INF, 0}; // ou 0
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return combina(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
pi upd(int i, int x, int p, int l, int r) { // O(log(n))
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = {x, 1};
    int m = (l+r)/2;
    return seg[p] = combina(upd(i, x, 2*p, l, m), upd(i, x, 2*p+1, m+1, r));
}
int n, m;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n -1);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i, x; cin >> i >> x;
            upd(i, x, 1, 0, n - 1);
        } else { // op == 2
            int a, b; cin >> a >> b;
            auto [x, cnt] = qry(a, b-1, 1, 0, n - 1);
            cout << x << " " << cnt << endl;
        }
    }
}