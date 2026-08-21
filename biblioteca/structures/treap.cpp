#include <bits/stdc++.h>

using namespace std;

// Gerador de números aleatórios robusto
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Treap {
    struct Node {
        int key;       // Chave de busca (mantém a propriedade da BST)
        int prior;     // Prioridade (mantém a propriedade do Heap)
        int sz;        // Tamanho da subárvore (Crucial para Order Statistics)
        int l, r;      // Filhos esquerdo e direito (índices)

        Node() : key(0), prior(0), sz(0), l(0), r(0) {}
        Node(int k) : key(k), prior(rng()), sz(1), l(0), r(0) {}
    };

    vector<Node> tree;
    int root;

    Treap() {
        tree.push_back(Node()); // Índice 0 atua como nullptr seguro
        root = 0;
    }

    int newNode(int key) {
        tree.push_back(Node(key));
        return tree.size() - 1;
    }

    int sz(int t) { return tree[t].sz; }

    // Atualiza as informações do nó (neste caso, apenas o tamanho)
    void upd(int t) {
        if (!t) return;
        tree[t].sz = 1 + sz(tree[t].l) + sz(tree[t].r);
    }

    // Divide a árvore t em duas: l (chaves <= key) e r (chaves > key)
    void split(int t, int key, int &l, int &r) {
        if (!t) {
            l = r = 0;
            return;
        }
        // Se a chave atual for menor ou igual, ela e todo seu filho esquerdo vão para 'l'
        if (tree[t].key <= key) {
            split(tree[t].r, key, tree[t].r, r);
            l = t;
        } 
        // Se a chave atual for maior, ela e todo seu filho direito vão para 'r'
        else {
            split(tree[t].l, key, l, tree[t].l);
            r = t;
        }
        upd(t); // Sempre atualize após modificar a estrutura
    }

    // Une duas árvores l e r. ATENÇÃO: O maior valor em 'l' deve ser <= ao menor em 'r'
    void merge(int &t, int l, int r) {
        if (!l || !r) {
            t = l ? l : r;
            return;
        }
        // O nó com maior prioridade vira a raiz
        if (tree[l].prior > tree[r].prior) {
            merge(tree[l].r, tree[l].r, r);
            t = l;
        } else {
            merge(tree[r].l, l, tree[r].l);
            t = r;
        }
        upd(t);
    }

    // --- OPERAÇÕES PADRÃO DE BST ---

    // Insere uma nova chave (Esta implementação permite duplicatas. Comporta-se como multiset)
    void insert(int key) {
        int t1, t2;
        split(root, key, t1, t2);
        int novo = newNode(key);
        merge(root, t1, novo);
        merge(root, root, t2);
    }

    // Remove UMA ocorrência da chave (se existir)
    void erase(int key) {
        int t1, mid, t2;
        // Isola os nós menores que a chave
        split(root, key - 1, t1, mid); 
        // Do que sobrou, isola os nós estritamente iguais à chave
        split(mid, key, mid, t2);      
        
        // Se houver algum nó igual à chave, removemos apenas a raiz desse grupo (uma ocorrência)
        if (mid) {
            merge(mid, tree[mid].l, tree[mid].r);
        }
        
        // Junta tudo de volta
        merge(root, t1, mid);
        merge(root, root, t2);
    }

    // --- OPERAÇÕES ESPECIAIS (ORDER STATISTICS) ---

    // Retorna a K-ésima menor chave (1-indexed). Retorna -1 se K for inválido.
    int kth_element(int k) {
        int cur = root;
        while (cur) {
            int left_sz = sz(tree[cur].l);
            if (k == left_sz + 1) return tree[cur].key; // Encontrou!
            
            if (k <= left_sz) {
                cur = tree[cur].l; // Busca na esquerda
            } else {
                k -= (left_sz + 1); // Desconta os elementos já passados
                cur = tree[cur].r;  // Busca na direita
            }
        }
        return -1; 
    }

    // Conta quantos elementos na Treap são estritamente MENORES que 'key' (Equivalente à posição do elemento)
    int count_less(int key) {
        int t1, t2;
        split(root, key - 1, t1, t2);
        int res = sz(t1);
        merge(root, t1, t2);
        return res;
    }

    // Função auxiliar para imprimir as chaves em ordem crescente
    void print(int t) {
        if (!t) return;
        print(tree[t].l);
        cout << tree[t].key << " ";
        print(tree[t].r);
    }
    void printAll() { print(root); cout << "\n"; }
};
