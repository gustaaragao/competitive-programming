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

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAXN 1000005

vector<int> adj[MAXN];
ll values[MAXN];
int n;
vector<ll> lis;
int ans[MAXN];

// u -> nó atual
// p -> pai do nó atual
void dfs(int u, int p) {
    // Passo 1: Encontrar o o valor value[u] na subseq
    // Lembre-se: lower_bound() encontra o primeiro MENOR
    auto it = lower_bound(all(lis), values[u]);
    int pos = it - lis.begin();
    
    // Passo 2: Salvar o estado anterior para backtracking
    bool extended = false;
    ll old_value = -1;

    if (it == lis.end()) {
        // values[u] é maior que todos os valores da LIS -> podemos adicionar values[u] na LIS
        extended = true; 
    } else {
        // values[u] é <= que todos os valores da LIS -> podemos substituir
        old_value = lis[pos];
    }

    // Passo 3: Atualizar a LIS
    if (extended) {
        lis.pb(values[u]);
    } else {
        lis[pos] = values[u];
    }

    ans[u] = lis.size();

    for (int v : adj[u]) {
        if (v != p) { // Garante que não estamos voltando para o pai
            dfs(v, u);
        }
    }

    if (extended) {
        lis.pop_back();
    } else {
        lis[pos] = old_value;
    }
}

signed main() {
    FAST_IO

    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        int b = i;
        a--; b--; // 1-indexed -> 0-indexed
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        values[i] = x;
    }

    dfs(0, -1);

    for (int i = 1; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}