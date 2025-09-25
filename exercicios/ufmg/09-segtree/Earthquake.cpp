#include <bits/stdc++.h>
using namespace std; 

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAXN 100005
int n, m, power, v[MAXN], seg[MAXN*4];
int single(int x) {return x;}
int neutral() {return INF;}
int merge(int a, int b) {return min(a, b);}
int build(int p=1, int l=0, int r=n-1) { // O(n)
    if (l == r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
int qry(int a, int b, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
int upd(int i, int x, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = single(x);
    int m = (l+r)/2;
    return seg[p] = merge(upd(i, x, 2*p, l, m), upd(i, x, 2*p+1, m+1, r));
}
int destroy_and_count(int a, int b, int power, int p=1, int l=0, int r=n-1) {
    // O mínimo do segmento é maior que o power, logo nenhum prédio foi derrubado
    if (seg[p] > power) return 0;
    // O intervalo do nó atual está fora do intervalo desejado
    if (b < l or a > r) return 0;
    if (l == r) {
        // Caso Base: encontramos um prédio e destruímos ele
        seg[p] = INF;
        return 1;
    }
    int m = (l+r)/2;
    int ans = 0;
    ans += destroy_and_count(a, b, power, 2*p, l, m);
    ans += destroy_and_count(a, b, power, 2*p+1, m+1, r);
    // Atualizado o mínimo dos nós
    seg[p] = merge(seg[2*p], seg[2*p+1]);
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    fill(v, v+MAXN, neutral());
    build(); // SegTree inicializada com o neutral (INF)
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i, x; cin >> i >> x;
            upd(i, x);
        } else {
            int a, b; cin >> a >> b >> power;
            cout << destroy_and_count(a, b-1, power) << endl;
        }
    }
}