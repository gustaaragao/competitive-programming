#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct DynamicLazySegTree {
    struct Node {
        T sum, lazy;
        int l, r; // Índices dos filhos no vector
        Node() : sum(0), lazy(0), l(0), r(0) {}
    };

    vector<Node> tree;
    long long min_val, max_val;
    T neutro = 0;

    // Construtor: define o limite do intervalo global (ex: 1 até 10^9)
    DynamicLazySegTree(long long min_val, long long max_val) : min_val(min_val), max_val(max_val) {
        tree.push_back(Node()); // Índice 0 é o nó nulo (vazio e imutável)
        tree.push_back(Node()); // Índice 1 é a raiz global da árvore
    }

    // Função encapsulada para criar nós com segurança
    int create_node() {
        tree.push_back(Node());
        return tree.size() - 1;
    }

    // Resolve a preguiça pendente e garante a criação dos filhos
    void push(int node, long long l, long long r) {
        if (tree[node].lazy != 0) {
            // Aplica a soma no nó atual (val * tamanho do intervalo)
            tree[node].sum += tree[node].lazy * (r - l + 1);

            // Se não for folha, propaga para os filhos
            if (l != r) {
                // Cria os filhos dinamicamente caso não existam
                if (tree[node].l == 0) {
                    int new_l = create_node();
                    tree[node].l = new_l; 
                }
                if (tree[node].r == 0) {
                    int new_r = create_node();
                    tree[node].r = new_r;
                }
                // Passa a preguiça para frente
                tree[tree[node].l].lazy += tree[node].lazy;
                tree[tree[node].r].lazy += tree[node].lazy;
            }
            tree[node].lazy = 0;
        }
    }

    // Update de intervalo
    void update(int node, long long l, long long r, long long ql, long long qr, T val) {
        push(node, l, r);
        if (ql > r || qr < l) return;
        
        if (ql <= l && r <= qr) {
            tree[node].lazy += val;
            push(node, l, r);
            return;
        }

        long long mid = l + (r - l) / 2;

        // Garante que os filhos existem antes de descer neles
        if (tree[node].l == 0) {
            int new_l = create_node();
            tree[node].l = new_l;
        }
        if (tree[node].r == 0) {
            int new_r = create_node();
            tree[node].r = new_r;
        }

        // SALVA OS ÍNDICES EM VARIÁVEIS ANTES DA RECURSÃO (Prevenção de RTE!)
        int esq = tree[node].l;
        int dir = tree[node].r;

        update(esq, l, mid, ql, qr, val);
        update(dir, mid + 1, r, ql, qr, val);

        tree[node].sum = tree[tree[node].l].sum + tree[tree[node].r].sum;
    }

    // Query de intervalo
    T query(int node, long long l, long long r, long long ql, long long qr) {
        // Se o nó é 0, significa que essa parte da árvore nunca foi tocada
        if (node == 0 || ql > r || qr < l) return neutro; 
        
        push(node, l, r);
        if (ql <= l && r <= qr) return tree[node].sum;

        long long mid = l + (r - l) / 2;
        return query(tree[node].l, l, mid, ql, qr) + query(tree[node].r, mid + 1, r, ql, qr);
    }

    // --- FUNÇÕES DA MAIN ---
    
    // Adiciona 'val' no intervalo [l, r]
    void update(long long l, long long r, T val) {
        update(1, min_val, max_val, l, r, val);
    }

    // Retorna a soma do intervalo [l, r]
    T query(long long l, long long r) {
        return query(1, min_val, max_val, l, r);
    }
};

/* COMO USAR NA MAIN:
 * // Cria uma árvore para o intervalo de 1 até 1 bilhão
 * DynamicLazySegTree<long long> st(1, 1000000000LL);
 * * st.update(10, 50000, 5);         // Soma 5 em todos os elementos de 10 até 50.000
 * st.update(40000, 1000000000LL, 2); // Soma 2 em todos de 40.000 até 1.000.000.000
 * * long long ans = st.query(1, 45000); // Consulta a soma
 */
