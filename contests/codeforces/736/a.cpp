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

void solve(){
    int p; cin >> p;
    /*
    P é primo e P >= 5, logo P é ímpar.
    -> Logo P - 1 é par, logo divisível por 2. Ou seja, P mod 2 = 1.
    Com isso, podemos tomar a = 2, t. q. P mod a = 1.
    Precisamos encontrar um b t. q. P mod b = 1, ou seja, podemos pegar P mod (P-1) = 1

    Portanto, a = 2 e b = P - 1 (P mod 2 = P mod b = 1).
    */
    int a = 2, b = p - 1;
    cout << a << " " << b << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}