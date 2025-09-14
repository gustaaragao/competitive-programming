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
typedef tuple<int, int, int> ti;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAXN 200005

signed main(){
    FAST_IO
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> impares;
        ll soma_pares = 0;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            if (x % 2 == 0) {
                soma_pares += x;
            } else {
                impares.pb(x);
            }
        }
        // Não há ímpares -> Não é possível somar na resposta
        if (impares.empty()) {
            cout << 0 << endl;
            continue;
        }

        /*
        A estratégia Gulosa é a seguinte:
        - Começamos desativado e pegamos o maior ímpar possível para ativar e somar na nossa resposta
        - Agora, como estamos ativos, podemos somar todos os pares.
        - Com isso, resta apenas somar os (k - 1) ímpares:
            - Se estiver ativo, visitamos o menor ímpar, pois esse ímpar será descartado
            - Senão, visitamos o maior ímpar, ativamos e somamos esse ímpar na resposta
        - Enfim, note que sempre somamos na resposta da seguinte forma:
            resposta = soma_pares + soma_dos_k/2_maiores_valores_impares
        */
        sort(all(impares));
        
        ll ans = 0;
        int k = impares.size();
        ll soma_impares = 0;
        for (int i = k - 1; i >= k / 2; i--) {
            soma_impares += impares[i];
        }
        ans = soma_pares + soma_impares;
        cout << ans << endl;
    }
}