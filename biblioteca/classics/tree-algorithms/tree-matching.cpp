#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define endl '\n' // << flush
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl
#define uniq(x) sort(all(x)); v.erase(unique(all(x)), x.end())
typedef pair<int, int> pi;
typedef long long ll;

// const int MOD = 1e9 + 7; // 998244353
// const int INF = 0x3f3f3f3f;
// const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 2e5 + 5;

int n, dp[2][MAXN];
// bool vis[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
    dp[0][v] = dp[1][v] = 0;
    // prefixo e sufixo das respostas dos filhos
    vector<int> pref, suff;
    bool leaf = true;
    for (auto u : adj[v]) if (u != p) {
        leaf = false;
        dfs(u, v);
    }
    if (leaf) return;

    for (auto u : adj[v]) if (u != p) {
        pref.pb(max(dp[0][u], dp[1][u]));
        suff.pb(max(dp[0][u], dp[1][u]));
    }

    for (int i = 1; i < (int) pref.size(); i++) {
        pref[i] += pref[i-1];
    }
    for (int i = (int) suff.size() - 2; i >= 0; i--) {
        suff[i] += suff[i+1];
    }

    // Caso eu não escolha a aresta (v, x), eu tenho dp[0][v] = SOMATÓRIO DAS RESPOSTAS DOS FILHOS
    dp[0][v] = suff[0];

    // Caso eu escolha formar uma aresta (v, x)
    int ci = 0;
    for (auto u : adj[v]) if (u != p) { // percorrer apenas para os filhos de v
        int left = (ci == 0) ? 0 : pref[ci-1];
        int right = (ci == (int) suff.size() - 1) ? 0 : suff[ci+1];
        dp[1][v] = max(dp[1][v], 1 + (left + dp[0][u] + right));
        ci++;
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
       int u, v; cin >> u >> v; u--,v--;
       adj[u].pb(v);
       adj[v].pb(u);
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[1][0]) << endl;
}

signed main() {
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}
