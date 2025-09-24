#include <bits/stdc++.h>
using namespace std; 
#define endl '\n'
#define MAXN 100005
int n, q, v[MAXN], seg[MAXN*4], lazy[MAXN*4], leafs[MAXN];
// Funções de Apoio
int single(int x) { return x; }
int neutral() { return 0; }
int merge(int a, int b) { return a + b;}
// Função de Propagação
void prop(int p, int l, int r) { // O(1)
    seg[p] += lazy[p]*(r-l+1);
	if (l != r) {
        lazy[2*p] += lazy[p]; 
        lazy[2*p+1] += lazy[p];
    }
    lazy[p] = 0;
}
// p -> índice na segtree, [l, r] -> intervalo da subarray
int build(int p=1, int l=0, int r=n-1) { // O(n)
    lazy[p] = 0;
    if (l == r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
// query no intervalo [a, b]
int qry(int a, int b, int p=1, int l=0, int r=n-1) {
    prop(p, l, r);
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
// update -> Para todo v[i] += x, com a <= i <= b.
int upd(int a, int b, int x, int p=1, int l=0, int r=n-1) { // 
    prop(p, l, r);
    if (a <= l and r <= b) {
		lazy[p] += x;
		prop(p, l, r);
		return seg[p];
	}
	if (b < l or r < a) return seg[p];
	int m = (l+r)/2;
	return seg[p] = merge(upd(a, b, x, 2*p, l, m), upd(a, b, x, 2*p+1, m+1, r));
}
// Função para visitar as folhas, ou seja, o v[]
void get_leafs (int p = 1, int l = 0, int r = n - 1) { // O(n)
    prop(p, l, r);
    if (l == r) {
        leafs[l] = seg[p];
        return;
    }
    int m = (l+r)/2;
    get_leafs(2*p, l, m);
    get_leafs(2*p+1, m+1, r);
};
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