#include <bits/stdc++.h>

using namespace std;

// Gerador de números aleatórios robusto
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct ImplicitTreap {
    struct Node {
        int val;       // Valor do elemento
        int prior;     // Prioridade (Heap)
        int sz;        // Tamanho da subárvore
        
        // --- ADICIONE SUAS VARIÁVEIS DE QUERY/LAZY AQUI ---
        long long sum; // Exemplo de Query: Soma do subsegmento
        bool rev;      // Exemplo de Lazy: Inverter o subsegmento
        
        int l, r;      // Filhos esquerdo e direito (usando índices)

        Node() : val(0), prior(0), sz(0), sum(0), rev(false), l(0), r(0) {}
        Node(int v) : val(v), prior(rng()), sz(1), sum(v), rev(false), l(0), r(0) {}
    };

    vector<Node> tree;
    int root;

    ImplicitTreap() {
        // O índice 0 age como um nó nulo (nullptr)
        tree.push_back(Node()); 
        root = 0;
    }

    int newNode(int val) {
        tree.push_back(Node(val));
        return tree.size() - 1;
    }

    int sz(int t) { return tree[t].sz; }

    // Atualiza as informações do nó baseado nos filhos (Cima para Baixo)
    void upd(int t) {
        if (!t) return;
        tree[t].sz = 1 + sz(tree[t].l) + sz(tree[t].r);
        
        // --- ATUALIZE SUAS QUERIES AQUI ---
        tree[t].sum = tree[t].val + tree[tree[t].l].sum + tree[tree[t].r].sum;
    }

    // Propaga as atualizações preguiçosas para os filhos (Baixo para Cima)
    void push(int t) {
        if (!t) return;
        
        // --- APLIQUE E PROPAGUE SUAS LAZY TAGS AQUI ---
        if (tree[t].rev) {
            swap(tree[t].l, tree[t].r); // Inverte os filhos
            if (tree[t].l) tree[tree[t].l].rev ^= true;
            if (tree[t].r) tree[tree[t].r].rev ^= true;
            tree[t].rev = false; // Limpa a tag
        }
    }

    // Divide a árvore t em duas: l (tamanho k) e r (o restante)
    void split(int t, int k, int &l, int &r) {
        if (!t) {
            l = r = 0;
            return;
        }
        push(t); // SEMPRE dê push antes de descer na árvore
        
        int left_sz = sz(tree[t].l);
        if (left_sz >= k) {
            split(tree[t].l, k, l, tree[t].l);
            r = t;
        } else {
            split(tree[t].r, k - left_sz - 1, tree[t].r, r);
            l = t;
        }
        upd(t); // SEMPRE dê update depois de modificar a estrutura
    }

    // Une duas árvores l e r em uma única árvore t
    void merge(int &t, int l, int r) {
        push(l); push(r); // SEMPRE dê push antes de mesclar
        
        if (!l || !r) {
            t = l ? l : r;
            return;
        }
        if (tree[l].prior > tree[r].prior) {
            merge(tree[l].r, tree[l].r, r);
            t = l;
        } else {
            merge(tree[r].l, l, tree[r].l);
            t = r;
        }
        upd(t);
    }

    // --- OPERAÇÕES DE ALTO NÍVEL ---

    // Insere um valor na posição 'pos' (0-indexed)
    void insert(int pos, int val) {
        int t1, t2;
        split(root, pos, t1, t2);
        int novo = newNode(val);
        merge(root, t1, novo);
        merge(root, root, t2);
    }

    // Remove o elemento da posição 'pos' (0-indexed)
    void erase(int pos) {
        int t1, t2, t3;
        split(root, pos, t1, t2);
        split(t2, 1, t2, t3);
        // t2 é o nó a ser removido (fica isolado e é ignorado)
        merge(root, t1, t3);
    }

    // Exemplo: Inverte um subarray [L, R]
    void reverse_range(int L, int R) {
        int t1, mid, t2;
        split(root, L, t1, mid);
        split(mid, R - L + 1, mid, t2);
        
        tree[mid].rev ^= true; // Aplica a Lazy Tag
        
        merge(root, t1, mid);
        merge(root, root, t2);
    }

    // Exemplo: Retorna a soma do subarray [L, R]
    long long query_sum(int L, int R) {
        int t1, mid, t2;
        split(root, L, t1, mid);
        split(mid, R - L + 1, mid, t2);
        
        long long res = tree[mid].sum; // Coleta a resposta
        
        merge(root, t1, mid);
        merge(root, root, t2);
        return res;
    }

    // Função auxiliar para imprimir (in-order)
    void print(int t) {
        if (!t) return;
        push(t);
        print(tree[t].l);
        cout << tree[t].val << " ";
        print(tree[t].r);
    }
};
