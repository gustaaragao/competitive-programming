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

const int MAXN = 1e5 + 10;

ll n, k, v[MAXN], seg[MAXN*4], lazy[MAXN*4], suff[MAXN], pref[MAXN];

ll single(ll x) {return x;}
ll neutral() {return LINF;}
ll merge(ll a, ll b) {return min(a, b);}
ll build(ll p=1, ll l=0, ll r=n-1) {
    if (l == r) return seg[p] = single(v[l]);
    ll m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
ll qry(ll a, ll b, ll p=1, ll l=0, ll r=n-1) {
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    ll m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
ll upd(ll i, ll x, ll p=1, ll l=0, ll r=n-1) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = single(x);
    ll m = (l+r)/2;
    return seg[p] = merge(upd(i, x, 2*p, l, m), upd(i, x, 2*p+1, m+1, r));
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    // Prefixo
    pref[0] = v[0];
    for (int i = 1; i < n; i++) 
        pref[i] = min(pref[i-1], v[i]);
    // Sufixo
    suff[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--) {
        suff[i] = min(suff[i+1], v[i]);
    }
    // Build SegTree para v[i] + i
    for (int i = 0; i < n; i++) v[i] += i;
    build();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll cand1 = LINF, cand2 = LINF, cand3 = LINF;
        // Prefix
        if (i - k >= 0) cand1 = pref[i - k];
        // Suffix
        if (i + 1 < n) cand2 = suff[i + 1];
        // Window
        ll begin = max(0LL, i - k + 1);
        cand3 = (k - i) + qry(begin, i);
        ll new_min = min({cand1, cand2, cand3});
        ans = max(ans, new_min);
    }
    cout << ans << endl;
}
