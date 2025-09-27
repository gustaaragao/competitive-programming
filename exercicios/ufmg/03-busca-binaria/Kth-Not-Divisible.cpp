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

ll n, k;

bool valid(ll m) {
    ll f = m - (m / n);
    return f >= k;
}

void solve(){
    cin >> n >> k;
    ll l = 0, r = LINF;
    while (l < r) {
        ll m = (l+r)/2;
        if (!valid(m)) l = m+1;
        else r = m;
    }
    cout << l << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve();
}

/*
Um número n divide quantos números de 1 até x?
- Resposta: piso(x / n)
Logo, n não divide x - piso(x / n) números.

Temos f(x) = x - piso(x / n), precisamos encontrar o primeiro x 
t.q f(x) >= k.
*/