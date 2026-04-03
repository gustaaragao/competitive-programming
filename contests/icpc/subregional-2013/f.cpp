#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define endl '\n' //<< flush
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cerr << #x << " = " << x << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> pi;
// const int MOD = 1e9 + 7; // 998244353;
// const int INF = 0x3f3f3f3f;
// const ll LINF = 0x3f3f3f3f3f3f3f3fll;
// const int MAXN = 2e5+5;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int sum = accumulate(all(v), 0LL);
    if (sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> pos; pos.pb(0);
    for (int i = 0; i < n - 1; i++) {
        pos.pb(pos.back() + v[i]);
    }

    int ans = 0, l = sum / 3;
    for (int i = 0; i < n; i++) {
        int p = pos[i];
        bool a = binary_search(all(pos), p+l);
        bool b = binary_search(all(pos), p+2*l);
        if (a and b) ans++;
    }

    cout << ans << endl;
}
