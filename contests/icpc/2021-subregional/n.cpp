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

struct fenw {
    int n;
    vector<int> bit;
    fenw() {}
    fenw(int size) {
        n = size;
        bit.assign(size + 1, 0);
    }
    int qry(int r) {
        int ans = 0;
        for (int i = r + 1; i > 0; i -= i & -i) 
            ans += bit[i];
        return ans;
    }
    void upd(int r, int x) {
        for (int i = r + 1; i <= n; i += i & -i) bit[i] += x;
    }
};

// REFAZER O CÓDIGO
signed main(){
    FAST_IO

    int y, n; cin >> y >> n;
    // mp_vagas[ano] -> ano das vagas
    map<int, vector<int>> mp_vagas;   
    vector<int> vagas(y+1);
    for (int i = 1; i <= y; i++) {
        cin >> vagas[i];
        mp_vagas[vagas[i]].pb(i);

    }

    // mp_query[num de vagas] -> indices dos querys
    map<int, vector<int>> mp_query;    
    vector<ti> comp(n+1);
    for (int i = 1; i <= n; i++) {
        // a -> aposentadoria
        // p -> colocacao
        // (a + f) -> termino do acompanhamento
        auto &[a, p, f] = comp[i];
        cin >> a >> p >> f;
        if (p > vagas[a]) {
            mp_query[p].pb(i);
        }
    }

    vector<int> ans(n+1, 0);
    fenw tree(y+1);
    for (int i = 1000005; i >= 1; i--) {
        for (auto ano : mp_vagas[i]) {
            tree.upd(ano, 1);
        }
        for (auto id_query : mp_query[i]) {
            auto [a, p, f] = comp[id_query];
            ans[id_query] = tree.qry(a+f) - tree.qry(a);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}