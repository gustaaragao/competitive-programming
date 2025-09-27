#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

template <class T>
using ord_set = tree<
T,              // Tipo da Chave
null_type,      // Tipo do Valor -> Caso seja definido, a ED vira um std::map
less<T>,        // greater<T> -> Ordem Decrescente
rb_tree_tag,    // Red-black Tree -> Inserção, Remoção e Busca em O(log(n))
tree_order_statistics_node_update
>;

#define MAXN 200005
int n, k, cnt[MAXN];

void solve(){
    cin >> n >> k;
    fill(cnt, cnt+MAXN, 0);
    ord_set<int> s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
        s.insert(x);
    };
    // Menores que K que apareceram
    int menores = s.order_of_key(k);
    if (menores == k) {
        cout << cnt[k] << endl;
        return;
    }
    int ans = 0;
    int menores_desaparecidos = k - menores;
    while (cnt[k] != 0 && menores_desaparecidos != 0) {
        // Pegar repetições de k e preencher os vazios anteriores
        menores_desaparecidos--;
        cnt[k]--;
        ans++;
    }
    ans += cnt[k] + menores_desaparecidos;
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}