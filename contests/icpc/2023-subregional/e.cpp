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

#define MAXN 1000005

// freq[] armazena a qtd de vezes que o valor N apareceu
ll freq[MAXN];
// nxt[] armazena o valor resultado ao fazer a operação X - sum(X) --> sum(i) é a soma de dígitos de i
ll nxt[MAXN];

ll sum(ll x) { // log10(X)
    ll ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

// Como o K <= 10^9, não podemos testar cada abelha
signed main(){
    FAST_IO

    ll n, k; cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        freq[x]++;
    }

    for (int i = 0; i < MAXN; i++) {
        nxt[i] = i - sum(i);
    }

    for (int i = MAXN - 1; i >= 0; i--) {
        if (freq[i] == 0) continue;
        
        if (k <= freq[i]) {
            // Encontramos a resposta para o problema
            cout << sum(i) << endl;
            return 0;
        }
        
        k -= freq[i];
        freq[nxt[i]] += freq[i];
    }

    // Caso saia do loop, significa que todas as flores foram "consumidas". Logo, sobrou nada para nossa abelhinha :(
    cout << 0 << endl;
}