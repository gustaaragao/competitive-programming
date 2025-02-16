// Busca em Grafos - Busca em Largura
// O(n + m) -> n: vertices | m: arestas

#include <bits/stdc++.h>
using namespace std; 

#define endl '\n'

// Matriz de Adjacencia -> O(1)
struct GrafoMatriz {
public:
    vector<vector<bool>> matriz;
    int n;

    GrafoMatriz(int _n) : n(_n), matriz(n, vector<bool>(n, false)) {}

    void add_matriz(vector<vector<bool>> _matriz) { matriz = _matriz; }

    void add_aresta(int inicio, int fim) {
        matriz[inicio][fim] = true;
        // matriz[fim][inicio] = true; // Grafo nao direcionado
    }
};

void bfs(const GrafoMatriz &g, const int &inicio) {
    int n = g.n;
}

void dfs(const GrafoMatriz &g, const int &inicio) {

}

// Lista de Adjacencia -> O(n + m) --> n: vertices | m: arestas
struct GrafoLista {
public:
    vector<vector<int>> lista;
    int n;

    GrafoLista(int _n) : n(_n), lista(_n) {}

    void add_lista(vector<vector<int>> _lista) { lista = _lista; }

    void add_aresta(int inicio, int fim) {
        lista[inicio].push_back(fim);
        // lista[fim].push_back(inicio); // Grafo nao direcionado 
    }
};

void bfs(const GrafoLista &g, const int &inicio, const int &destino = 0) {
    int n = g.n;
    vector<bool> visitados(g.n, false); visitados[inicio] = true;
    queue<int> fila; fila.push(inicio);
    vector<int> dist(n), pais(n); // Vetores para recuperacao do caminho para destino
    pais[inicio] = -1;
    while (!fila.empty()) {
        int atual = fila.front(); fila.pop();
        cout << atual << " ";
        for (int filho : g.lista[atual]) {
            if (!visitados[filho]) {
                visitados[filho] = true;
                fila.push(filho);
                dist[filho] = dist[atual] + 1; pais[filho] = atual;
            }
        }
    }
    cout << endl;
    // Recuperar destino
    if (!visitados[destino]) cout << "NAO";
    else {
        vector<int> caminho;
        for (int vert = destino; vert != -1; vert = pais[vert]) 
            caminho.push_back(vert);
        reverse(caminho.begin(), caminho.end());
        for (int v : caminho) cout << v << " ";
        cout << endl;
    }
}

void dfs(const GrafoLista &g, const int &inicio) {
    int n = g.n;
    vector<bool> visitados(g.n, false); visitados[inicio] = true;
    stack<int> pilha; pilha.push(inicio);
    while (!pilha.empty()) {

    }
}

int main() {
    GrafoLista g = GrafoLista(5);
    g.add_aresta(0, 1);
    g.add_aresta(0, 3);
    g.add_aresta(1, 0);
    g.add_aresta(1, 2);
    g.add_aresta(1, 4);
    g.add_aresta(2, 1);
    g.add_aresta(3, 0);
    g.add_aresta(3, 4);
    g.add_aresta(1, 3);

    bfs(g, 0, 4);

    return 0;
}