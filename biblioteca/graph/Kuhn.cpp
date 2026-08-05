#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
// Algoritmo de Kuhn para encontrar Emparelhamento Máximo (Maximum Matching) em O(VE)
struct kuhn {
    // observação: A = {0, 1, ..., n} e B = {0, 1, ..., m}
    // ou seja estão 0-indexed
    // n -> esquerda, m -> direita
    int n, m;
    // adj[u] = vizinhos (da direita) do esquerdo u
    vector<vi> adj;
    // ma, mb -> o emparelhamento em si
    vi ma, mb;
    vector<bool> vis;
    kuhn(int n_, int m_) : n(n_), m(m_), adj(n),
        vis(n+m), ma(n, -1), mb(m, -1) {}
    void add(int a, int b) {adj[a].pb(b);}
    bool dfs(int v) {
        vis[v] = true;
        for (auto u : adj[v]) if (!vis[u+n]) {
            vis[u+n] = true;
            if (mb[u] == -1 or dfs(mb[u])) {
                // u está livre ou consigo realocar o dono atual de u?
                ma[v] = u, mb[u] = v;
                return true;
            }
        }
        return false;
    }
    // retorna o tamanho do emparelhamento máximo
    // Para recuperar o matching, basta olhar 'ma' e 'mb'
    int matching() { // O(V*E)
        int ret = 0;
        for (auto &x : adj) shuffle(all(x), rng); // heurística
        bool aum = true;
        while (aum) {
            for (int u = 0; u < m; u++) vis[u+n] = 0;
            aum = false;
            for (int v = 0; v < n; v++)
                if (ma[v] == -1 and dfs(v)) ret++, aum = true;
        }
        return ret;
    }
};
// recover() responde o problema de minimum vertex cover
// quantidade mínima de vértices escolhidos que garante que todas arestas estão sendo "observadas"
// Segundo o Teorema de Kőnig, a cardinalidade do minimum vertex cover é o emparelhamento máximo
// esse problema é NP-Difícil para grafos no geral e é possível resolver em tempo polinomial para bipartidos
pair<vi, vi> recover(kuhn &k) { // O(V*E)
    k.matching();
	int n = k.n, m = k.m;
	for (int i = 0; i < n+m; i++) k.vis[i] = 0;
	for (int i = 0; i < n; i++) if (k.ma[i] == -1) k.dfs(i);
	vector<int> ca, cb;
	for (int i = 0; i < n; i++) if (!k.vis[i]) ca.push_back(i);
	for (int i = 0; i < m; i++) if (k.vis[n+i]) cb.push_back(i);
    // {caras da particao A, caras da particao B}
	return {ca, cb};
}
// podemos responder o minimum edge cover (qtd mínima de arestas escolhidas que garante que todos
// os vértices são observados) com o Teorema de Gallai: 
// minimum edge cover = total de vértices - emparelhamento máximo 
// https://codeforces.com/group/Acy2lotTJD/contest/700424/problem/B
signed main() {
    // o grafo precisa ser bipartido
    // n = esquerda, m = direita, e = qtd de arestas
    int n, m, e; cin >> n >> m >> e;
    kuhn k(n, m);
    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b; a--, b--;
        k.add(a, b);
    }
    // emparelhamento máximo
    cout << k.matching() << endl;
    // mostrar as arestas escolhidas
    for (int i = 0; i < n; i++) {
        if (k.ma[i] != -1) {
            cout << i << " " << k.ma[i] << endl; 
        }
    }
    // se quiser a cobertura mínima por vértices:
    // auto [ca, cb] = recover(K);
    // se quiser a cobertura mínima por arestas:
    // cout << (n+m) - k.matching() << endl;
}
/*
# Definições
Dado um grafo bipartido G(n, m), o maximum match (emparelhamento máximo)
consiste na quantidade de aresta uv que podemos escolher de tal forma que
os vértices u, v não pertencem a nenhuma outra aresta escolhida.
- um vértice é saturado se ele pertence a uma aresta de algum matching M
- um caminho ALTERNANDO é um caminho onde as arestas pertencem ou não (alternando) a um match M.
- um caminho AUMENTADO é um caminho ALTERNANDO onde os vértices do início e fim são não-saturados. 
Berge's Lemma
-> Um matching M é máximo sse não existe nenhum caminho AUMENTADO no matching
O algoritmo de Kuhn é uma aplicação do Berge's Lemma
https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html
*/