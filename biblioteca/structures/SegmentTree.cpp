#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int INF = 0x3f3f3f3f;
#define MAXN 1000000
int n, v[MAXN], seg[4*MAXN]; // a SegTree está 0-INDEXED
// Funções de Apoio
int single(int x) {return x;}
int neutral() {return -INF;}
int merge(int a, int b) {return max(a, b);}
// p -> índice na segtree, [l, r] -> intervalo da subarray
int build(int p=1, int l=0, int r=n-1) { // O(n)
    if (l == r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
// query no intervalo [a, b]
int qry(int a, int b, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
// update -> v[i] = x
int upd(int i, int x, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = single(x);
    int m = (l+r)/2;
    return seg[p] = merge(upd(i, x, 2*p, l, m), upd(i, x, 2*p+1, m+1, r));
}
// primeira posição >= x em [a, b] (ou -1, caso não exista)
// Obs.: Só funciona na SegTree de Máximos
int first_above(int x, int a, int b, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (b < l or r < a or seg[p] < x) return -1;
	if (l == r) return l;
	int m = (l+r)/2;
	int left = first_above(x, a, b, 2*p, l, m);
	if (left != -1) return left;
	return first_above(x, a, b, 2*p+1, m+1, r);
}
// última posição >= x em [a, b] (ou -1, caso não exista)
// Obs.: Só funciona na SegTree de Máximos
int last_above(int x, int a, int b, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (b < l or r < a or seg[p] < x) return -1;
	if (l == r) return l;
	int m = (l+r)/2;
	int right = last_above(x, a, b, 2*p+1, m+1, r);
	if (right != -1) return right;
	return last_above(x, a, b, 2*p, l, m);
}
// retorna a posição i do vetor do Kth 1
// Obs.: Só funciona na SegTree de Soma
// k é 1-INDEXED e o RETORNO é 0-INDEXED
int find_kth(int k, int p=1, int l=0, int r=n-1) {
    if (k > seg[p]) return -1;
    if (l == r) return l;
    int m = (l + r) / 2;
    if (seg[p*2] >= k)
        return find_kth(k, p*2, l, m);
    else
        return find_kth(k - seg[p*2], p*2+1, m+1, r);
}
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    // Você pode inicializar v[] com um valor neutro
    // fill(v, v+MAXN, netrual());
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