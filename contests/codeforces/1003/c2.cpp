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

void solve(){
    int n, m; cin >> n >> m;
    vector<ll> a(n); 
    for(auto &x : a) cin >> x;    
    vector<ll> b(m);
    for(auto &x : b) cin >> x;
    sort(all(b));
    if (is_sorted(all(a))) {
        cout << "YES" << endl;
        return;
    }
    // Guloso e BS
    a[0] = min(a[0], b[0] - a[0]);
    for (int i = 1; i < n; i++) {
        // Guloso: Queremos min(a[i], b[j] - a[i]) >= a[i-1]
        // -> Para encontrar b[j] - a[i] >= a[i-1] => b[j] >= a[i] + a[i-1] -> Podemos fazer uma busca binária
        ll cand1 = a[i], cand2 = LINF;        
        auto it = lower_bound(all(b), a[i] + a[i-1]);
        if (it != b.end()) cand2 = *it - a[i];
        if (cand1 >= a[i-1]) {
            // Os dois candidatos são válidos
            a[i] = min(cand1, cand2); // Escolha o menor dos candidatos
            // min(cand1, LINF) = cand1, caso cand2 não tenha sido encontrado
        } else {
            // cand1 não é válido
            if (cand2 == LINF) {
                // Não encontramos o cand2
                cout << "NO" << endl;
                return;
            } else {
                // Encontramos o cand2
                a[i] = cand2;
            }
        }
    }
    cout << "YES" << endl;
}

signed main(){
    FAST_IO
    int tc; cin >> tc;
    while (tc--) solve();
}