#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int qtd_pares = 0, qtd_impares = 0;
    int ultimo_par = -1, ultimo_impar = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            qtd_pares++;
            ultimo_par = i+1;
        } else {
            qtd_impares++;
            ultimo_impar = i+1;
        }
    }
    if (qtd_pares == 1) {
        cout << ultimo_par << endl;
    } else {
        cout << ultimo_impar << endl;
    }
}
