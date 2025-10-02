#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
typedef pair<int ,int> pi;
typedef tuple<int ,int, int> ti;
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

template <class T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define BARCO_ENTRADA -1
#define BARCO_SAIDA 0
#define PEIXE 1

const int MAXN = 1e5 + 10;

int n, m;
ti b[MAXN]; pi p[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    vector<ti> ev; map<pi, int> mp;
    for (int i = 0; i < n; i++) {
        auto &[x, r, h] = b[i];
        cin >> x >> r >> h;
        ev.emplace_back(x-r, BARCO_ENTRADA, h); // Início
        ev.emplace_back(x+r+1, BARCO_SAIDA, h); // Fim -> +1 para marcar após o fim do retângulo
        mp[{x, h}] = r; // Marca o cículo
    }
    for (int i = 0; i < m; i++) {
        auto &[x, y] = p[i];
        cin >> x >> y;
        ev.emplace_back(x, PEIXE, y);
    }

    sort(all(ev));
    int ans = 0;
    multiset<int> h;
    for (auto [x, tipo, y] : ev) {
        if (tipo == PEIXE) {
            if (h.empty()) continue;
            int h_max = *h.rbegin();
            if (y <= h_max) {
                ans++;
                continue;
            }
            // Brutar o círculo
            int ok = 0;
            for (int i = x - 10; i <= x + 10; i++) {
                for (int j = y - 10; j <= y + 10; j++) {
                    // mp.count(x) melhor que mp[x]
                    if (mp.count({i, j})) {
                        int r = mp[{i, j}];
                        int xx = i-x;
                        int yy = j-y;
                        if ((xx*xx) + (yy*yy) <= r*r) {
                            ok = 1;
                        }
                    }
                }
            }
            ans += ok;
        } else { // BARCO
            if (tipo == BARCO_ENTRADA) h.insert(y);
            else h.erase(h.find(y));
        }
    }
    cout << ans << endl;
}