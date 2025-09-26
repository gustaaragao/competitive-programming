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
    greater<T>,        // greater<T> -> Ordem Decrescente
    rb_tree_tag,    // Red-black Tree -> Inserção, Remoção e Busca em O(log(n))
	tree_order_statistics_node_update
>;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll x, y, h, v; cin >> x >> y >> h >> v;
    vector<pi> hor(h);
    for (int i = 0; i < h; i++) {
        cin >> hor[i].ff >> hor[i].ss;
    }
    vector<pi> ver(v);
    for (int i = 0; i < v; i++) {
        cin >> ver[i].ff >> ver[i].ss;
    }
    sort(all(hor)), sort(all(ver));
    ll ans = 1 + (h+v) + (h*v);
    ord_set<int> sh, sv;
    // Interseção V-V
    for (auto [beg, end] : ver) {
        ans += sv.order_of_key(end);
        sv.insert(end);
    }
    // Interseção H-H
    for (auto [beg, end] : hor) {
        ans += sh.order_of_key(end);
        sh.insert(end);
    }
    cout << ans << endl;
}