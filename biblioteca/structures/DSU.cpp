#include <bits/stdc++.h>
using namespace std;
struct dsu {
    // pai = representante
    vector<int> parent, size;
    dsu(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int i) { 
        // Path Compression
        return parent[i] = (parent[i] == i) ? i : find(parent[i]);
    }
    void uni(int a, int b) { // o pai de a se torna pai de b
        a = find(a), b = find(b);
        if (a != b) {
            // a -> maior árvore
            if (size[a] < size[b]) { // Small to Large Otimization
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
// https://cp-algorithms.com/data_structures/disjoint_set_union.html