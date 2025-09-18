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
    ll b; cin >> b;
    // a[] já está ordenado de forma não-decrescente -> faz 0 operações
    bool ordenado_crescente = true;
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i-1]) {
            ordenado_crescente = false;
            break;
        }
    }
    if (ordenado_crescente) {
        cout << "YES" << endl;
        return;
    }
    // Guloso
    a[0] = min(a[0], b - a[0]);
    for (int i = 1; i < n; i++) {
        if (min(a[i], b - a[i]) >= a[i-1]) {
            // Escolher o menor possível que valide a desigualdade ">=" ajuda no próximo passo
            a[i] = min(a[i], b - a[i]);
        } else {
            if (max(a[i], b - a[i]) >= a[i-1]) {
                // Caso o maior possível valide a desigualdade, mantemos ele.
                a[i] = max(a[i], b - a[i]);
            } else {
                cout << "NO" << endl;
                return;
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