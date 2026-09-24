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
const int MAXN = 1e6+10;

ll n, v[MAXN], dp[MAXN][3][3];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];

    // dp[n][3][3]
    // -1 -1 -1 
    // memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int vi = i;
                if (v[0] != -1 && v[0] != i) continue;
                if (v[1] != -1 && v[1] != j) continue;
                if (v[2] != -1 && v[2] != k) continue;
                if (i + j + k == 3) {
                    // cout << i << " " << j << " " << k << endl;
                    dp[2][j][k]++;
                }
            }
        }
    }

    // cout << dp[2][2][1] << endl;

    for (ll i = 3; i < n; i++) {
        if (v[i] == -1) {
            for (ll j = 0; j < 3; j++) {
                for (ll k = 0; k < 3; k++) {
                    for (ll l = 0; l < 3; l++) {
                        if (j + k + l == 3) dp[i][l][j] += dp[i-1][k][l];
                    }
                }
            }
        } else {
            for (ll j = 0; j < 3; j++) {
                for (ll k = 0; k < 3; k++) {
                    if (j + k + v[i] == 3) dp[i][k][v[i]] += dp[i-1][j][k];
                }
            }
        }
    }

    ll ans = 0;
    // for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < 3; i++) {
            for (ll j = 0; j < 3; j++) {
                // cout << dp[k][i][j] << " ";
                ans += dp[n-1][i][j];
            }
            // cout << endl;
        }
    // }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout.precision(10); cout.setf(ios::fixed);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}