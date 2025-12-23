#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(x) (int) (x).size()

const int MAXN = 2e5 + 10;

// xp[i] -> experiencia 'parcial' do jogador i
// add[i] -> experiencia a ser adicionada para todo o componente
// A cada chamada de uni, ele atualiza a xp de todos os vértices do componente menor.
// Ele compensa os valores de add subtraindo o add do pai do maior componente.
int n, m, parent[MAXN], add[MAXN], xp[MAXN];
vector<int> childs[MAXN];

void build() {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        childs[i].push_back(i);
    }
}

int find(int i) {
    return parent[i] = (parent[i] == i) ? i : find(parent[i]);
}

void uni(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) {
        if (sz(childs[a]) < sz(childs[b])) swap(a, b);
        // Atualizando a pontuação
        for (auto x : childs[b]) {
            xp[x] += add[b];
            // o componente B não fazia parte do grupo de A, logo não pode receber add[a] em um próximo Union
            xp[x] -= add[a]; 
        }
        add[b] = 0;
        parent[b] = a;
        childs[a].insert(
            childs[a].end(), 
            childs[b].begin(), childs[b].end()
        );
    }
}

void add_xp(int x, int v) {
    x = find(x);
    add[x] += v;
}

int get_xp(int x) {
    return xp[x] + add[find(x)];
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    build();
    while (m--) {
        string op; cin >> op;
        if (op == "join") {
            int x, y; cin >> x >> y; x--, y--;
            uni(x, y);
        } else if (op == "add") {
            int x, v; cin >> x >> v; x--;
            add_xp(x, v);
        } else { // op == get           
            int x; cin >> x; x--;
            cout << get_xp(x) << endl;
        }
    }
}