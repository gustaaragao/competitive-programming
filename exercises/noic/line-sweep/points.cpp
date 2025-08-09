#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define int long long

#define HORIZONTAL_INICIO 0
#define VERTICAL 1
#define HORIZONTAL_FIM 2

// 10^-6 <= y <= 10^6
#define MAX_Y 2 * 1e6 + 1

struct fenw {
    int n;
    vector<int> bit;

    fenw() {}
    fenw(int size) {
        n = size;
        bit.assign(size + 1, 0);
    }
    // query do prefixo a[0] + a[1] + ... + a[r]
    int qry(int r) {
        int ans = 0;
        for (int i = r + 1; i > 0; i -= i & -i) // i & -i retorna os bits menos signativos de i 
            ans += bit[i];
        return ans;
    }

    // atualiza o valor a[r] = x
    void upd(int r, int x) {
        for (int i = r + 1; i <= n; i += i & -i) bit[i] += x;
    }
};

signed main(){ _

    int n; cin >> n;
    
    vector<ti> ev;
    int y_horizontal[n];
    pi y_vertical[n];
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            // Reta Vertical
            ev.emplace_back(x1, VERTICAL, i);
            y_vertical[i] = {y1, y2};
        } else {
            // Reta Horizontal
            ev.emplace_back(x1, HORIZONTAL_INICIO, i);
            ev.emplace_back(x2, HORIZONTAL_FIM, i);
            y_horizontal[i] = y1;
        }
    }

    sort(all(ev));

    fenw tree(MAX_Y);

    int ans = 0;
    for (auto [x, tipo, id] : ev) {
        if (tipo == HORIZONTAL_INICIO) {
            int yh = y_horizontal[id];
            tree.upd(yh + 1e6, +1); // Liga a reta Horizontal
        } else if (tipo == HORIZONTAL_FIM) {
            int yh = y_horizontal[id];
            tree.upd(yh  + 1e6, -1); // Desliga a reta Horizontal
        } else { // VERTICAL
            auto [y1, y2] = y_vertical[id];
            ans += tree.qry(y2  + 1e6) - tree.qry(y1  + 1e6);
        }
    }

    cout << ans << endl;
}