#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define endl '\n' //<< flush
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> pi;
// const int MOD = 1e9 + 7; // 998244353;
// const int INF = 0x3f3f3f3f;
// const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 2e5+5;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    // cada negócio cabe no máximo 2 pessoas
    // caso o mais leve e o mais pesado caibam juntos, levo os dois
    // caso contrário, levo apenas o mais pesado (pi <= x)
    int i = 0, j = n - 1, ans = 0;
    while (i <= j) {
        if (i == j) {
            ans++;
            break;
        }

        if (a[i] + a[j] <= x) {
            i++;
            j--;
        } else {
            j--;
        }
        ans++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
}
