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
        ll n, m; cin >> n >> m;
        vector<pair<ll, ll>> ev(n);
        for (int i = 0; i < n; i++) {
            cin >> ev[i].ff >> ev[i].ss;
        }
        
        ll pos = 0, atual = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int d = ev[i].ff - pos;
            if (atual == ev[i].ss) {
                // Paridades iguais
                if (d % 2 == 0) {
                    ans += d;
                } else {
                    ans += d - 1;
                }
            } else {
                // Paridades diferentes
                if (d % 2 == 0) {
                    ans += d - 1;
                } else {
                    ans += d;
                }
            }
            pos = ev[i].ff;
            atual = ev[i].ss;
        }
        if (pos < m) {
            ans += m - pos;
        }
        cout << ans << endl;
    }
}