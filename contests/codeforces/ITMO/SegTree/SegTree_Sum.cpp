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

ll a[MAXN], seg[4*MAXN], n, m;
ll build(ll p, ll l, ll r) {
    if (l == r) return seg[p] = a[l];
    ll m = (l+r)/2;
    return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
}
ll qry(ll a, ll b, ll p, ll l, ll r) {
    if (b < l or a > r) return 0;
    if (a <= l and r <= b) return seg[p];
    ll m = (l+r)/2;
    return qry(a, b, 2*p, l, m) + qry(a, b, 2*p+1, m+1, r);
}
ll upd(ll i, ll x, ll p, ll l, ll r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    ll m = (l+r)/2;
    return seg[p] = upd(i, x, 2*p, l, m) + upd(i, x, 2*p+1, m+1, r);
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (ll i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n-1);
    while (m--) {
        ll op; cin >> op;
        if (op == 1) {
            ll i, x; cin >> i >> x;
            upd(i, x, 1, 0, n - 1);
        } else {
            ll a, b; cin >> a >> b;
            cout << qry(a, b-1, 1, 0, n - 1) << endl;
        }
    }
}