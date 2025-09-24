// https://resources.beecrowd.com/repository/UOJ_2658.html
#include <bits/stdc++.h>
using namespace std; 
#define endl '\n'
#define MAXN 100005
const int INF = 0x3f3f3f3f;
struct node {
    // Cada nó vai armazenar a frequência das notas no Segmento e a moda
    int freq[9] = {0}, mode;
};
int n, q;
int v[MAXN]; 
node seg[MAXN*4];
int lazy[MAXN*4];
node single(int x) { 
    node res;
    res.freq[x] = 1;
    res.mode = x;
    return res;
}
node neutral() { return {{0}, 0}; }
node merge(node a, node b) { 
    node res;
    int cand_mode = -1, cnt_mode = -INF;
    for (int i = 0; i < 9; i++) {
        res.freq[i] = a.freq[i] + b.freq[i];
        if (res.freq[i] > cnt_mode) {
            cnt_mode = res.freq[i];
            cand_mode = i;
        } else if (res.freq[i] == cnt_mode) {
            cand_mode = max(cand_mode, i);
        }
    }
    res.mode = cand_mode;
    return res;
}
void prop(int p, int l, int r) {
    if (lazy[p] == 0) return;
    int temp_freq[9] = {0}, f = lazy[p];
    for (int i = 0; i < 9; i++) {
        temp_freq[(i + f) % 9] = seg[p].freq[i];
    }

    int cand_mode = -1, cnt_mode = -INF;
    for (int i = 0; i < 9; i++) {
        seg[p].freq[i] = temp_freq[i];
        if (seg[p].freq[i] > cnt_mode) {
            cnt_mode = seg[p].freq[i];
            cand_mode = i;
        } else if (seg[p].freq[i] == cnt_mode) {
            cand_mode = max(cand_mode, i);
        }
    }
    seg[p].mode = cand_mode;

    if (l != r) {
        lazy[2*p] = (lazy[2*p] + f) % 9; 
        lazy[2*p+1] = (lazy[2*p+1] + f) % 9; 
    }
    lazy[p] = 0;
}
node build(int p=1, int l=0, int r=n-1) { // O(n)
    lazy[p] = 0;
    if (l == r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
node qry(int a, int b, int p=1, int l=0, int r=n-1) {
    prop(p, l, r);
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
node upd(int a, int b, int x, int p=1, int l=0, int r=n-1) {
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
int leafs[MAXN];
void get_leafs (int p = 1, int l = 0, int r = n - 1) { // O(n)
    prop(p, l, r);
    if (l == r) {
        for (int i = 0; i < 9; i++) {
            if (seg[p].freq[i] == 1) {
                leafs[l] = i;
                break;
            }
        }
        return;
    }
    int m = (l+r)/2;
    get_leafs(2*p, l, m);
    get_leafs(2*p+1, m+1, r);
};
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    fill(v, v+MAXN, 1);
    build();
    while (q--) {
        int a, b; cin >> a >> b;
        auto [freq, f] = qry(a, b);
        upd(a, b, f);
    }
    // O(n)
    get_leafs();
    for (int i = 0; i < n; i++) { // O(n)
        cout << leafs[i] << endl;
    }
    // O(nlog(n))
    // for (int k = 0; k < n; k++) {
    //     auto [freq, mode] = qry(k, k);
    //     cout << mode << endl;
    // }
}