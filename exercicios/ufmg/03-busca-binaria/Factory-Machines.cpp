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

const int MAXN = 2e5 + 10;
ll n, t, k[MAXN];

bool possible(ll m) {
    ll prod = 0;
    for (int i = 0; i < n; i++) {
        prod += (m / k[i]);
        if (prod >= t) return true;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> k[i];
    sort(k, k+n);
    // r -> Uma máquina que demora 1e9 para produzir sozinha 1e9 produtos
    ll l = 0, r = 1e18;
    while (l < r) {
        ll m = l + (r-l)/2;
        if (possible(m)) r = m;
        else l = m + 1;
    }
    cout << l << endl;
}