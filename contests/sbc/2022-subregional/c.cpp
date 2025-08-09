#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAX_X 1001
#define MAX_Y 1001

bool corte_hor[MAX_X + 1][MAX_Y + 1];
bool corte_ver[MAX_X + 1][MAX_Y + 1];

signed main(){ _

    int n; cin >> n;
    vector<pi> pontos;
    for (int i = 0; i < n + 1; i++) {
        int x, y; cin >> x >> y;
        pontos.eb(x, y);
    }

    auto [x_atual, y_atual] = pontos[0];
    for (int i = 1; i < n + 1; i++) {
        if (true) {
            // Corte Horizontal
            // corte_hor[i][j] = true;
        } else {
            // Corte Vertical
            // corte_ver[i][j] = true;
        }
    }
    
}