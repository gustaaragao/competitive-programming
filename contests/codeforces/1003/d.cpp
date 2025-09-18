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
    int n, m; cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    // Ordenar de forma decrescente do maior para o menor em relação a soma
    sort(all(arr), [](vector<ll> a, vector<ll> b) {
        return accumulate(all(a), 0) > accumulate(all(b), 0); 
    });
    ll ans = 0, prefix = 0;
    for (auto v : arr) {
        for (int i = 0; i < m; i++) {
            prefix = prefix + v[i];
            ans += prefix; 
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}

/*
n -> número de vetores
m -> tamanho do vetor

O score = SUM(Si), com i = 0 até n - 1, sendo Si a soma de prefixo até o índice i.

Se m = 1, para maximizar o score podemos concatenar os vetores do maior para o menor.

Se m = 2, temos n vetores v1, v2, ..., vn.

Vamos considerar que n = 2, ou seja, temos 2 vetores a, b. 

Além disso, vamos supor que a concatenação ótima a + b = [a0, a1, b0, b1]

score(a+b) = a0 + (a0 + a1) + (a0 + a1 + b0) + (a0 + a1 + b0 + b1)
score(a+b) = 4*a0 + 3*a1 + 2*b0 + 1*b1
score(a+b) = 2*a0 + 2*a1 + a0 + (a0 + a1) + b0 + (b0 + b1)
score(a+b) = 2*sum(a) + score(a) + score(b)

De maneira análogo,
score(b+a) = 2*sum(b) + score(b) + score(a)

Ou seja, escolhe entre a + b e b + a, se queremos maximizar o score, devemos escolher
o vetor com a maior soma.

Por "indução", isso vale para para qualquer n e m.
*/