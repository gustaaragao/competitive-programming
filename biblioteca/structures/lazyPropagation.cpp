#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct LazySegTree {
    int n;
    vector<T> tree, lazy;
    T neutro = 0; // Elemento neutro para a soma

    // Construtor
    LazySegTree(int n) : n(n) {
        tree.assign(4 * n, neutro);
        lazy.assign(4 * n, 0); // 0 indica que não há atualização pendente
    }

    T combina(T a, T b) {
        return a + b;
    }

    // Resolve a preguiça pendente no nó atual e repassa para os filhos
    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            // Aplica a atualização no nó atual. 
            // Como é soma de intervalo, multiplicamos o valor pelo tamanho do intervalo.
            tree[node] += lazy[node] * (r - l + 1); 

            // Se não for folha, repassa a preguiça para os filhos
            if (l != r) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            // Limpa a preguiça do nó atual
            lazy[node] = 0;
        }
    }

    // Build interno
    void build(int node, int l, int r, const vector<T>& arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);
        tree[node] = combina(tree[2 * node], tree[2 * node + 1]);
    }

    // Update interno em intervalo [ql, qr]
    void update(int node, int l, int r, int ql, int qr, T val) {
        push(node, l, r); // Sempre dá push antes de interagir com o nó

        if (ql > r || qr < l) return; // Fora do escopo

        if (ql <= l && r <= qr) { // Totalmente dentro do escopo
            lazy[node] += val; // Acumula a preguiça
            push(node, l, r);  // Atualiza este nó e passa a preguiça pra baixo
            return;
        }

        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        
        tree[node] = combina(tree[2 * node], tree[2 * node + 1]);
    }

    // Query interna no intervalo [ql, qr]
    T query(int node, int l, int r, int ql, int qr) {
        push(node, l, r); // Sempre dá push antes de ler o valor de um nó

        if (ql > r || qr < l) return neutro;
        if (ql <= l && r <= qr) return tree[node];
        
        int mid = l + (r - l) / 2;
        return combina(query(2 * node, l, mid, ql, qr),
                       query(2 * node + 1, mid + 1, r, ql, qr));
    }

    // --- FUNÇÕES PARA USAR NA MAIN ---
    
    void build(const vector<T>& arr) { 
        build(1, 0, n - 1, arr); 
    }

    // Adiciona 'val' em todos os elementos no intervalo [l, r]
    void update(int l, int r, T val) { 
        update(1, 0, n - 1, l, r, val); 
    }
    
    // Retorna a soma do intervalo [l, r]
    T query(int l, int r) { 
        return query(1, 0, n - 1, l, r); 
    }
};

/* COMO USAR NA MAIN:
 * vector<int> arr = {1, 2, 3, 4, 5};
 * LazySegTree<int> st(arr.size());
 * st.build(arr);
 * * st.update(1, 3, 10); // Adiciona 10 no intervalo [1, 3]. Array fica: {1, 12, 13, 14, 5}
 * int ans = st.query(1, 4); // Consulta a soma de [1, 4] -> 12 + 13 + 14 + 5 = 44
 */
