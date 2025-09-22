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

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m; cin >> n >> m;
    ll mat[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    ll ans = 0;
    for (int j = 0; j < m; j++) {
        ll m = -1;
        for (int i = 0; i < n; i++) {
            m = max(m, mat[i][j]);
        }
        ans += m;
    }
    cout << ans << endl;
}