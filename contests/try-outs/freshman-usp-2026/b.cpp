#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
// #define int long long
#define endl '\n' //<< flush
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cerr << #x << " = " << x << endl
#define pdbg(x) cerr << #x << " = " << x.ff << "," << x.ss << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pi> vpi;
const ld EPS = 1e-9;
const int MOD = 1e9 + 7; // 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 1e2+10;

ll n;

void solve() {
    // x = o seu valor final
    // para todo a[i] > x, vc doa cnt += (a[i] - x + 1)
    // cnt >= (x - a[0])
    cin >> n;
    vi a(n); for (auto &e : a) cin >> e;
    // for (auto x : a) cout << x << " ";
    // cout << endl;
    ll l = 1, r = 1e18;
    ll ans = LINF;
    while (l <= r) {
        vi tmp = a;
        ll m = (l + r) / 2;
        // cout << "m = " << m << endl;
        ll cnt = 0;
        ll precisa = m - a[0];
        for (ll i = 1; i < n; i++) {
            if (tmp[i] >= m) {
                cnt += tmp[i] - m + 1;
                tmp[i] = m-1;
                // precisa -= min(precisa, a[i]);
                // cnt += a[i];
            }
        }

        // cout << "cnt = " << cnt << endl;
        // cada um doa valor entre [a[i] -m + 1, a[i]] e a soma = (m - a[0])
        for (ll i = 1; i < n; i++) {
            if (cnt < precisa) {
                cnt += min(precisa - cnt, (ll) tmp[i]);
            }
        }
        // cout << "cnt = " << cnt << endl;
        // cout << "precisa = " << precisa << endl;
        if (precisa >= cnt) {
            r = m-1;
            if (precisa == cnt) ans = cnt;
        } else if (precisa < cnt) {
            l = m+1;
        }
    }

    cout << ans << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout.precision(10); cout.setf(ios::fixed);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}