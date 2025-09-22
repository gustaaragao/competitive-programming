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

#define MAXN 200005

int n;

void solve() {
    cin >> n;
    string enemy, gregory;
    cin >> enemy >> gregory;
    
    int ans = 0;
    vector<bool> taken(n, false);
    for (int i = 0; i < n; i++) {
        if (gregory[i] == '1') {
            if (enemy[i] == '0') {
                // Captura o da Esquerda
                ans++;
            } else if ((i - 1 >= 0) && enemy[i-1] == '1' && !taken[i-1]) {
                // Coluna i está livre
                ans++;
                taken[i-1] = true;
            } else if ((i + 1 < n) && enemy[i + 1] == '1' && !taken[i+1]) {
                // Captura o da direita
                ans++;
                taken[i+1] = true;
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}