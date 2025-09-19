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

const ll MAXN = 2e5 + 5;

vector<ll> D[MAXN];

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
 
    for (auto &e : a) cin >> e;
 
    vector<ll> cnt(n+1);
 
    vector<ll> max_nums;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        vector<ll> next;
        for (ll d : D[a[i]]) {
            cnt[d]++;
 
            if (cnt[d] != i+1) {
                ans = max(ans, cnt[d]);
            } else {
                next.pb(d);
            }
        }
 
        for (ll num : max_nums) {
            if (cnt[num] != i+1) {
                ans = max(ans, cnt[num]);
            }
        }
 
        max_nums = next;
 
        cout << ans << " "; 
    }
    cout << endl;
} 

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // Calculando os divisores de 1 até MAXN -> O(nlog(n))
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) { // j -> múltiplo de i
            D[j].pb(i);
        }
    }
    
    int tc; cin >> tc;
    while (tc--) solve();
}