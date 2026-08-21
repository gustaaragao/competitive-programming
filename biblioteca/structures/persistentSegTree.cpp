#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct PersistentSegTree {
    struct Node {
        T sum;
        int l, r; // Índices para o filho esquerdo e direito no vector 'tree'
        Node(T sum = 0, int l = 0, int r = 0) : sum(sum), l(l), r(r) {}
    };

    int n;
    vector<Node> tree;
    vector<int> roots; // Armazena o índice da raiz de cada versão
    T neutro = 0;      // Elemento neutro para a soma

    // Construtor
    PersistentSegTree(int n) : n(n) {
        // O índice 0 será o nosso nó "nulo" ou vazio
        tree.push_back(Node(neutro, 0, 0)); 
        roots.push_back(0); // A versão 0 aponta para o nó nulo inicialmente
    }

    T combina(T a, T b) {
        return a + b;
    }

    // Cria um novo nó copiando os dados de um nó existente
    int clone(int node_idx) {
        tree.push_back(tree[node_idx]);
        return tree.size() - 1;
    }

    // Build interno (Constrói a versão inicial baseada em um array)
    int build(int l, int r, const vector<T>& arr) {
        int node = tree.size();
        tree.push_back(Node()); // Cria um novo nó

        if (l == r) {
            tree[node].sum = arr[l];
            return node;
        }
        
        int mid = l + (r - l) / 2;
        tree[node].l = build(l, mid, arr);
        tree[node].r = build(mid + 1, r, arr);
        tree[node].sum = combina(tree[tree[node].l].sum, tree[tree[node].r].sum);
        
        return node;
    }

    // Update interno (Retorna o índice da nova raiz)
    int update(int prev_root, int l, int r, int pos, T val) {
        // Criamos uma cópia do nó atual da versão anterior
        int node = clone(prev_root);

        if (l == r) {
            tree[node].sum += val; // Altere para '=' se for substituição
            return node;
        }

        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            // Se a atualização for na esquerda, a direita se mantém apontando para o nó antigo
            tree[node].l = update(tree[prev_root].l, l, mid, pos, val);
        } else {
            // Se a atualização for na direita, a esquerda se mantém apontando para o nó antigo
            tree[node].r = update(tree[prev_root].r, mid + 1, r, pos, val);
        }
        
        tree[node].sum = combina(tree[tree[node].l].sum, tree[tree[node].r].sum);
        return node;
    }

    // Query interna no intervalo [ql, qr] em uma raiz específica
    T query(int node, int l, int r, int ql, int qr) {
        if (node == 0 || ql > r || qr < l) return neutro;
        if (ql <= l && r <= qr) return tree[node].sum;
        
        int mid = l + (r - l) / 2;
        return combina(query(tree[node].l, l, mid, ql, qr),
                       query(tree[node].r, mid + 1, r, ql, qr));
    }

    // --- FUNÇÕES PARA USAR NA MAIN ---

    // Constrói a versão 0 a partir de um array. 
    // Retorna o índice da versão criada (sempre será 1 se chamado logo após instanciar)
    int build(const vector<T>& arr) {
        int root_idx = build(0, n - 1, arr);
        roots.push_back(root_idx);
        return roots.size() - 1; // Retorna o ID da versão recém-criada
    }

    // Atualiza um elemento partindo de uma versão base.
    // Retorna o ID da nova versão criada.
    int update(int base_version, int pos, T val) {
        int new_root = update(roots[base_version], 0, n - 1, pos, val);
        roots.push_back(new_root);
        return roots.size() - 1; // Retorna o ID da nova versão
    }

    // Consulta no intervalo [l, r] de uma versão específica
    T query(int version, int l, int r) {
        return query(roots[version], 0, n - 1, l, r);
    }
};

/* COMO USAR NA MAIN:
 * vector<int> arr = {1, 2, 3, 4, 5};
 * PersistentSegTree<int> pst(arr.size());
 * * int v1 = pst.build(arr);             // v1 = 1. Versão 1: {1, 2, 3, 4, 5}
 * int v2 = pst.update(v1, 2, 10);      // v2 = 2. Versão 2: {1, 2, 13, 4, 5} (Soma 10 na pos 2)
 * int v3 = pst.update(v2, 4, -2);      // v3 = 3. Versão 3: {1, 2, 13, 4, 3} (Soma -2 na pos 4)
 * * int ans1 = pst.query(v1, 1, 3); // Consulta na versão 1 [1,3] -> 2 + 3 + 4 = 9
 * int ans2 = pst.query(v2, 1, 3); // Consulta na versão 2 [1,3] -> 2 + 13 + 4 = 19
 * int ans3 = pst.query(v3, 2, 4); // Consulta na versão 3 [2,4] -> 13 + 4 + 3 = 20
 */
