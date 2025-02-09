#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int n; cin >> n;
    
    string direcoes;
    
    set<pair<pair<int, int>, pair<int, int>>> caminhos;
    
    pair<pair<int, int>, pair<int, int>> caminho_atual = {{0, 0}, {0, 0}};
    pair<pair<int, int>, pair<int, int>> caminho_atual_invertido = {{0, 0}, {0, 0}};
    
    pair<int, int> novo_ponto = {0, 0};

    while (n--) {
        int temp = 0;

        caminhos.clear();

        cin >> direcoes;

        for (auto direcao : direcoes) {
            if (direcao == 'N') {
                novo_ponto.s++;
            } else if (direcao == 'S') {
                novo_ponto.s--;
            } else if (direcao == 'E') {
                novo_ponto.f++;
            } else { // direcao == 'W'
                novo_ponto.f--;
            }

            caminho_atual.f = caminho_atual.s;
            caminho_atual.s = novo_ponto;
            
            caminho_atual_invertido = caminho_atual;

            swap(caminho_atual_invertido.f, caminho_atual_invertido.s);

            if (caminhos.count(caminho_atual) || caminhos.count(caminho_atual_invertido)) {
                temp++;
            } else {
                caminhos.insert(caminho_atual);
                temp += 5;
            }
        }
        cout << temp << endl;
    }
    return 0;
}