#include <bits/stdc++.h>
using namespace std; 

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
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
typedef tuple<int, int, int> ti;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){
    FAST_IO

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        ll x, y; cin >> x >> y;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        // sort(all(a)); sort(all(b));
        ll ans = 0;
        // Retas Horizontais
        ans += lower_bound(all(a), y) - a.begin();
        // Retas Verticais
        ans += lower_bound(all(b), x) - b.begin();
        cout << ans << endl;
    }
}
// lower_bound(all(v), x) -> iterator de v[] para v[i] >= x