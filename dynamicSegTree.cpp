#include <bits/stdc++.h>
using namespace std;

struct DynamicSegTree {
    // A estrutura do nó fica escondida aqui dentro
    struct Node {
        long long sum;
        Node *l, *r;
        Node() : sum(0), l(nullptr), r(nullptr) {}
    };

    Node* root;
    long long min_val, max_val;

    // Construtor: define o limite mínimo e máximo do intervalo global
    DynamicSegTree(long long min_val, long long max_val) : min_val(min_val), max_val(max_val) {
        root = new Node();
    }

    // Update interno (Recursivo)
    void update(Node*& node, long long l, long long r, long long idx, long long val) {
        if (!node) node = new Node();
        if (l == r) {
            node->sum += val; // Altere para '=' se for substituição
            return;
        }
        
        long long m = l + (r - l) / 2; // Evita bugs de overflow e com números negativos
        if (idx <= m) {
            update(node->l, l, m, idx, val);
        } else {
            update(node->r, m + 1, r, idx, val);
        }
        
        long long leftSum = node->l ? node->l->sum : 0;
        long long rightSum = node->r ? node->r->sum : 0;
        node->sum = leftSum + rightSum;
    }

    // Query interna (Recursiva)
    long long query(Node* node, long long l, long long r, long long ql, long long qr) {
        if (!node || ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return node->sum;
        
        long long m = l + (r - l) / 2;
        return query(node->l, l, m, ql, qr) + query(node->r, m + 1, r, ql, qr);
    }

    // --- FUNÇÕES PARA USAR NA MAIN ---
    void update(long long idx, long long val) {
        update(root, min_val, max_val, idx, val);
    }

    long long query(long long ql, long long qr) {
        return query(root, min_val, max_val, ql, qr);
    }
};

/* COMO USAR NA MAIN:
 * // Cria uma árvore dinâmica para um intervalo de 1 até 1 bilhão
 * DynamicSegTree st(1, 1000000000); 
 * st.update(50000, 10);     // Soma 10 no índice 50.000
 * st.update(999999999, 5);  // Soma 5 no índice 999.999.999
 * long long ans = st.query(1, 1000000000); // Retorna 15
 */
