// Busca em Grafos - Busca em Largura
// O(n + m) -> n: vertices | m: arestas

#include <bits/stdc++.h>
using namespace std; 

#define endl '\n'

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
    
    void bfs(const GrafoLista &g, const int &inicio) {
        int n = g.n;
        vector<bool> visitados(g.n, false); visitados[inicio] = true;
        queue<int> fila; fila.push(inicio);
        while (!fila.empty()) {
            int atual = fila.front(); fila.pop();
            cout << atual << " ";
            for (int filho : g.lista[atual]) {
                if (!visitados[filho]) {
                    visitados[filho] = true;
                    fila.push(filho);
                }
            }
        }
    }
    
    // DFS Recursivo
    void dfs_recursivo_aux(const GrafoLista &g, const int &inicio, vector<bool> &visitados) {
        visitados[inicio] = true;
        cout << inicio << " ";
        for (int filho : g.lista[inicio]) {
            if (!visitados[filho]) dfs_recursivo_aux(g, filho, visitados);
        }
    }
    
    void dfs_recursivo(const GrafoLista &g, const int &inicio) {
        int n = g.n;
        vector<bool> visitados(n, false);
        dfs_recursivo_aux(g, inicio, visitados);
    }
    
    // DFS Interativo
    void dfs_interativo(const GrafoLista &g, const int &inicio) {
        int n = g.n;
        vector<bool> visitados(n, false);
        stack<int> pilha; pilha.push(inicio);
        while (!pilha.empty()) {
            int atual = pilha.top(); pilha.pop();
            if (!visitados[atual]) {
                cout << atual << " "; visitados[atual] = true;
            }
            for (int vizinho : g.lista[atual]) {
                if (!visitados[vizinho]) pilha.push(vizinho);
            }
        }
    }

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

// BFS
void bfs(const GrafoMatriz &g, const int &inicio) {
    int n = g.n;
    vector<bool> visitados(n, false); visitados[inicio] = true;
    queue<int> fila; fila.push(inicio);
    while (!fila.empty()) {
        int atual = fila.front(); fila.pop();
        cout << atual << " ";
        for (int vizinho = 0; vizinho < n; ++vizinho) {
            if (g.matriz[atual][vizinho] && !visitados[vizinho]) {
                visitados[vizinho] = true;
                fila.push(vizinho);
            }
        }
    }
}

// DFS Recursivo
void dfs_recursivo_aux(const GrafoMatriz &g, int atual, vector<bool> &visitados) {
    visitados[atual] = true;
    cout << atual << " ";
    for (int vizinho = 0; vizinho < g.n; ++vizinho) {
        if (g.matriz[atual][vizinho] && !visitados[vizinho]) {
            dfs_recursivo_aux(g, vizinho, visitados);
        }
    }
}

void dfs_recursivo(const GrafoMatriz &g, const int &inicio) {
    int n = g.n;
    vector<bool> visitados(n, false);
    dfs_recursivo_aux(g, inicio, visitados);
}

// DFS Iterativo
void dfs_interativo(const GrafoMatriz &g, const int &inicio) {
    int n = g.n;
    vector<bool> visitados(n, false);
    stack<int> pilha; pilha.push(inicio);
    while (!pilha.empty()) {
        int atual = pilha.top(); pilha.pop();
        if (!visitados[atual]) {
            cout << atual << " "; visitados[atual] = true;
            for (int vizinho = n - 1; vizinho >= 0; --vizinho) {
                if (g.matriz[atual][vizinho] && !visitados[vizinho]) {
                    pilha.push(vizinho);
                }
            }
        }
    }
}