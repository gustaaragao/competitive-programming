#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define PICO 1
#define VALE -1

int main(){ _

    int n; cin >> n;

    vector<int> h;
    h.push_back(0); 
    while (n--) {
        int x; cin >> x;
        h.push_back(x);
    }
    h.push_back(0);
    
    vector<pi> ev;
    for (int i = 1; i < h.size() - 1; i++) {
        if (h[i] > h[i-1] && h[i] > h[i+1]) {
            // o ponto i eh um pico
            ev.emplace_back(h[i], PICO);
        } else if (h[i] < h[i-1] && h[i] < h[i+1]) {
            // o ponto i eh um vale
            ev.emplace_back(h[i], VALE);
        }
    }

    sort(all(ev)); // Ordenar eh importante pois precisamos varrer da menor altura para maior altura de um pico/vale

    int acc = 2, ans = 2;
    for (auto [altura, tipo] : ev) {
        if (tipo == VALE) acc++;
        else acc--;
        ans = max(ans, acc);
    }

    cout << ans << endl;

    return 0;
}

/*
https://neps.academy/br/exercise/27

- A resposta >= 2. Pois para qualquer altura > 0, é possível fazer um corte que divida o desenho no mínimo em duas partes
- Podemos fazer uma busca por força bruta verificando cada altura Ai, tendo uma complexidade O(H), onde H é a altura máxima de 10**9 (não passa)
- A estratégia está em usar line sweep.
    -> Vamos fazer a leitura de todas as alturas e identificar picos e vales.
        -> Um pico é um ponto i onde h[i] > h[i - 1] e h[i] > h[i]
        -> Um vale é um ponto i onde h[i] < h[i - 1] e h[i] < h[i]
    -> Note que para i, j consecutivos, nao precisamos armazenar h[i] e h[j], basta um. (Essa é uma melhoria na perfomance do código).
    -> Cortar um vale, aumenta em 1 os pedaços
    -> Cortar um pico, diminui em 1 os pedaços
*/