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

#define MAXN 100005

ll p[MAXN];
int n, c, t; 

bool is_possible(ll ans) {
    if (ans == 0) return false;

    // Máximo que um competidor pode comer de pipoca
    ll max_por_competidor = ans * t;

    int competidores = 1;
    ll pipoca_atual = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] > max_por_competidor) {
            // Cada saco só pode ser consumido por um competidor
            return false;
        }
        if (pipoca_atual + p[i] > max_por_competidor) {
            competidores++;
            pipoca_atual = p[i];
        } else {
            pipoca_atual += p[i];
        }
    }
    // O objetivo é contar a qtd de competidores necessárias para consumir p[] no tempo ans
    return competidores <= c;
}

signed main(){
    FAST_IO

    cin >> n >> c >> t;
    ll soma = 0; ll maior = -1;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        soma += p[i];
        maior = max(maior, p[i]);
    }
    // low -> mínimo de tempo: um competidor consome sozinho o maior pacote
    ll low = (maior + t - 1) / t; // fórmula para teto: teto(a /b) = (a + b - 1) / b
    // low -> máximo de tempo: um competidor consome sozinho todos os pacotes
    ll high = (soma + t - 1) / t;
    
    ll ans = -1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (is_possible(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}