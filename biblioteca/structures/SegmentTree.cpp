#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int INF = 0x3f3f3f3f;
#define MAXN 1000000
int v[MAXN], seg[4*MAXN]; // a SegTree está 0-INDEXED
// FUNÇÕES DE APOIO
int single(int x) {return x;}
int neutral() {return INF;}
int merge(int a, int b) {return min(a, b);}
// p -> índice na segtree, [l, r] -> intervalo da subarray
int build(int p, int l, int r) { // O(n)
    if (l == r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
// query no intervalo [a, b]
int qry(int a, int b, int p, int l, int r) { // O(log(n))
    if (b < l or a > r) return neutral(); // ou 0
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
// update 
int upd(int i, int x, int p, int l, int r) { // O(log(n))
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = single(x);
    int m = (l+r)/2;
    return seg[p] = merge(upd(i, x, 2*p, l, m), upd(i, x, 2*p+1, m+1, r));
}
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    // Leitura de v[]
    for(int i = 0; i < n; i++) cin >> v[i];
    // Construir a SegTree
    build(1, 0, n - 1);
    // Query do intervalo a, b
    int a, b; cin >> a >> b;
    cout << qry(a, b, 1, 0, n - 1) << endl;
    // Update de v[i] = x
    int i, x; cin >> i >> x;
    cout << upd(i, x, 1, 0, n - 1) << endl;
}
/* Segment Tree ou SegTree ou Árvore de Segmentos
# Altura da árvore -> O(log(n))
# Qtd de nós -> 2n - 1 -> O(n)
-> Problemas de RMQ: Range Minimun Query
    -> Descobrir o mínimo de um intervalo [l, r]

-> Soma, Mínimo, Máximo, Produto, ... 
-> SegTree para qualquer operação ASSOCIATIVA: (A ? B) ? C = A ? (B ? C) 
*/