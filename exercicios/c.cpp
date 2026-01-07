#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define int ll
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
const int MOD = 1e9 + 7; // 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    int maxL = k-1, maxR = n-k, ans = 1;
    
    auto possible = [&](int l, int r) {
        int cost;
        if (l == 0 and r == 0) {
            cost = 0;
        } else if (l == 0) {
            cost = 2*r - 1;
        } else if (r == 0) {
            cost = 2*l - 1;
        } else {
            cost = l + r + max(l, r) - 1;
        }
        
        return cost <= m; 
    };

    for (int l = 0; l <= maxL; l++) {
        int low = 0, high = maxR, best = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(l, mid)) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (best != -1) ans = max(ans, l + best + 1);
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}