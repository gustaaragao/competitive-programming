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

#define MAXN 105

// n -> número de vértices
int n;
int w[MAXN][MAXN];
int dist[MAXN][MAXN];

void floyd_warshall() {
    for (int k = 0 ; k < n ; k++) {
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]) ;
            }
        }
    }
}
void initialize() {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF ;
            }
        }
    }
}

signed main(){
    FAST_IO
    
    cin >> n;

    initialize();

    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c; cin >> c;
            w[i][j] = c;
            dist[i][j] = min(dist[i][j], c);
        }
    }

    floyd_warshall();

    // Passo 1: Verificar a coerência da Matriz
    // -> Verifique se w[i][j] (voo direto) > dist[i][j]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] < w[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    // Passo 2: Contar voos diretos que podemos remover
    // -> Verificar se existe um k, com k != i e k != j, t.q. w[i][j] == w[i][k] + w[k][j]
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if (w[i][j] == w[i][k] + w[k][j]) {
                    // Encontramos um caminho i -> k -> j alternativo para i -> j
                    ans++;
                    break; // Não precisamos testar os outros k
                }
            }
        }
    } 

    cout << ans << endl;
}