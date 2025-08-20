#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

signed main(){ _

    int n; cin >> n;
    vector<int> start(2*n + 1, -1);
    map<int, int> pos;
    for (int i = 1; i <= 2*n; i++) {
        int x; cin >> x;
        // x já foi lido e armazenado em pos, guarde em start o pos. E o pos terá o último índice onde x apareceu
        if (pos[x]) start[x] = pos[x];
        pos[x] = i;
    }

    vector<int> dp_qtd_pares(2*n+1);    // Maximizar
    vector<int> dp_preco(2*n+1);        // Minimizar
    for (int i = 1; i <= 2*n; i++) {
        // Caso Geral 1: Não pegar nenhum elemento novo

        // Caso Geral 2: Pegar algum elemento novo
        // Caso 2.1: (dp_qtd_pares[i - 1] + 1) > dp_qtd_pares[j] --> Melhorou a quantidade de pares
        // Caso 2.2: (dp_qtd_pares[i - 1] + 1) == dp_qtd_pares[j] --> Não melhorou a quantidade de pares
        // -> Preciso verificar se isso minimiza o custo (dp_preco[i - 1] + (j - i) < dp_preco[j])
    }

    cout << dp_qtd_pares[2*n] << " " << dp_preco[2*n] << endl;
}