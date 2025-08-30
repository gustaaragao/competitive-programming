#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> pi;

const ll MOD = 1e9 + 7;
const ll MAXN = 4e7 + 5;
const ll MAXX = 1e15 + 5;
ll m, n, k;

signed main(){ _
    

    cin >> m >> n >> k;
    vector<ll> a(n); for (auto &e : a) cin >> e;

    vector<vector<pi>> adj_m(m, vector<pi>());

    for (ll i = 0; i < k; i++) {
        ll ind1, ind2, d; cin >> ind1 >> ind2 >> d;
        ind1--, ind2--;
        adj_m[ind1].push_back({ind2, d});
    }

    vector<ll> ans(m, -1);
    ll i = 0;
    for (ll p = 2; p*p <= 1e15; p++) {
        if (i >= m) break;
        if (a[adj_m[i][0].first] % p == 0) {
            ans[i] = p;
            for (auto [ind_n, d] : adj_m[i]) {
                while (d--) a[ind_n] /= p;
            }
            i++;
        }
    }
    
    for (ll i = 0; i < m; i++) {
        if (ans[i] == -1) {
            for (auto [ind_n, d] : adj_m[i]) {
                if (a[ind_n] > 1) ans[i] = a[ind_n];
            }
        }
    }
    
    for (ll i = 0; i < m; i++) cout << ans[i] << " ";
    cout << endl;

}