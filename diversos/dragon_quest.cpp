#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int t; cin >> t;
    while (t--) {
        int x, n, m;
        cin >> x >> n >> m;
        
        while (n > 0 && x > 20) {
            x = x / 2 + 10;
            n--;
        }
        
        if (x <= m * 10) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

    /*
    A abordagem gulosa aqui eh sempre usar todos os Void Absorptions possiveis enquanto
    a vida x > 20 e n > 0 e depois verificar se ao usar todos os Lightning Strikes deixa
    x <= 0. 

    - O motivo do x > 20.
    Tem a chance de usar o ataque V.A. e aumentar a vida atual do monstro.
    h / 2 + 10 < h -> - h / 2 < -10 -> h > 20.

    - A abordagem de buscar os melhores cenários locais não leva ao melhor caso, o último exemplo
    do sample mostra isso.

    Esse código aqui falha:
    int main(){ _
        int t; cin >> t;
        while (t--) {
            int x, n, m; cin >> x >> n >> m; 
            while ((n > 0 || m > 0)) {
                int hp_va = INF, hp_ls = INF;
                if (n > 0) hp_va = (x / 2) + 10;
                if (m > 0) hp_ls = x - 10;
                int novo_x = min(hp_va, hp_ls);
                if (novo_x >= x) break;
                x = novo_x;
                if (x == hp_va) n--;
                else m--;
                if (x <= 0) break;
            }
            cout << (x <= 0 ? "YES" : "NO") << endl;
        }
        return 0;
    }

    Uma prova para essa afirmação seria o seguinte contra exemplo
    x = 20, n = 1 e m = 2
    Com a estratégia, escolhemos usar a habilidade V. A
    Logo, novo_x = 20 / 2 + 10 = 20. Como novo_x >= x, damos break no loop e printamos "NO".
    Porém, a solução usando dois L. S. resolve o problema.
    */

