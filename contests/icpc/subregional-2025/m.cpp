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

#define MAXN 100005
int arr[MAXN], prefixos[MAXN], sufixos[MAXN];
int n; int k;

/*
O(nlog(n)) -> Mínimo em Prefixos e Sufixos + Multiset para achar mínimo de uma janela
Considere v[] o vetor de entrada.

vA[i] = v[i] + i (O vetor v[] somado pelos índices)
vB[i] = v[i] + k - (n - 1 - i) (O vetor após aplicar K numa posição i)

vB tem uma simplificação de notação, obviamente o fator "k - (n - 1 - i)" precisa ser >= 0

vA - vB = v[i] + i - (v[i] + k - (n - 1 - i))
        = k - n - 1, uma constante

Ou seja, ao aplicar o K = 3 em um vetor numa posição i
           i
# # # |? ? ?| # # # #

Podemos considerar, que o vetor resultante possui 3 partes:
1 - Prefixo
2 - Janela onde o K foi aplicado
3 - Sufixo

A menor altura de v[] consiste no min(min(prefixo), min(janela), min(sufixo)).

E a resposta considera no máximo de todas essas menores alturas.

Ou seja, vamos brutar a solução, porém devemos melhor a busca dos mínimos.

1 - Prefixo e 3 - Sufixo, podem ser resolvidos usando mínimo de prefixo e mínimo de sufixo.

2 - Janela onde o K foi aplicado, podemos descobrir o mínimo de uma janela do vetor v[i]+i,
pois o mínimo desse vetor também é o mínimo do vetor v[i] + k. Pois a distância entre eles
é uma constante (provamos isso no início).
*/ 
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    prefixos[0] = INF;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefixos[i] = min(prefixos[i-1], arr[i]);
    }
    sufixos[n+1] = INF;
    for (int i = n; i >= 1; i--) {
        sufixos[i] = min(sufixos[i+1], arr[i]);
    }
    multiset<int> s;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        s.insert(arr[i] + i);
        if (i - k > 0) {
            // A janela precisa remover itens do início
            s.erase(s.find(arr[i - k] + (i - k)));
        }
        int menor = *s.begin() + (k - i);
        if (i - k > 0) {
            // Há prefixo
            menor = min(menor, prefixos[i-k]);
        }
        if (i < n) {
            // Há sufixo
            menor = min(menor, sufixos[i+1]);
        }
        ans = max(menor, ans);
    }
    cout << ans << endl;
}