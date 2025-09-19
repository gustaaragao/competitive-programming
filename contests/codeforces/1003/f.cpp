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

#define MAXN 1000000
int n;
vector<int> adj[MAXN];
vector<int> vert(MAXN);

void solve(){
    cin >> n;
    fill(adj, adj + n, vector<int>({}));
    for (int i = 0; i < n; i++) {
        cin >> vert[i];
        vert[i]--;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    string ans = string(n, '0');
    for (int u = 0; u < n; u++) {
        // Conta a ocorrência dos valores lidos no caminho
        map<int, int> mp;
        mp[vert[u]]++;
        for (int v : adj[u]) {
            mp[vert[v]]++;
        }
        for (auto [a, b] : mp) {
            if (b >= 2) ans[a] = '1';
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}