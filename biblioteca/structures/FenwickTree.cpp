// Binary Indexed Tree ou Fenwick Tree
#include <bits/stdc++.h>
using namespace std;

struct fenw {
    int n;
    vector<int> bit;
    fenw() {}
    fenw(int size) {
        n = size;
        bit.assign(size + 1, 0);
    }
    // query do prefixo a[0] + a[1] + ... + a[r]
    int qry(int r) {
        int ans = 0;
        for (int i = r + 1; i > 0; i -= i & -i) // i & -i retorna os bits menos signativos de i 
            ans += bit[i];
        return ans;
    }
    // atualiza o valor a[r] = x
    void upd(int r, int x) {
        for (int i = r + 1; i <= n; i += i & -i) bit[i] += x;
    }
    // busca binária para o maior índice i (i < n) tal que qry(i) < x
    int bs(int x) {
        int i = 0, k = 0;
        while (1 << (k + 1) <= n) k++;
        while (k >= 0) {
            int nxt_i = i + (1 << k);
            if (nxt_i <= n && bit[nxt_i] < x) {
                i = nxt_i;
                x -= bit[i];
            }
            k--;
        }
        return i - 1;
    }
};