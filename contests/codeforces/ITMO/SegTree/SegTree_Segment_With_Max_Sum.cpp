#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define MAXN 1000000
struct node {
    ll sum, pref, suf, ans;
};

ll v[MAXN]; node seg[4*MAXN];

node single(ll x) {
    node n;
    n.sum = x;
    n.pref = n.suf = n.ans = max(0LL, x);
    return n;
}

node neutral() {return {-LINF, -LINF, -LINF, -LINF};}

node merge(node a, node b) {
    node n;
    n.sum = a.sum + b.sum;
    n.pref = max(a.pref, a.sum + b.pref);
    n.suf = max(b.suf, b.sum + a.suf);
    n.ans = max(max(a.ans, b.ans), a.suf + b.pref);
    return n;
}

node build(ll p, ll l, ll r) {
    if (l == r) return seg[p] = single(v[l]);
    ll m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}

node qry(ll a, ll b, ll p, ll l, ll r) {
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    ll m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}

node upd(ll i, ll x, ll p, ll l, ll r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = single(x);
    ll m = (l+r)/2;
    return seg[p] = merge(upd(i, x, 2*p, l, m), upd(i, x, 2*p+1, m+1, r));
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n - 1);
    cout << qry(0, n - 1, 1, 0, n - 1).ans << endl;
    while (m--) {
        ll i, x; cin >> i >> x;
        upd(i, x, 1, 0, n - 1);
        cout << qry(0, n - 1, 1, 0, n - 1).ans << endl;
    }
}

/*
Esse segmento máximo podemos chamar de x. E, sua soma é dada por:

seg = max(seg1, seg2, sufixo1 + prefixo2)

Podemos separar o segmento x em duas partes (1) e (2):
- seg1 -> é a resposta para o sub-segmento (1)
- seg2 -> é a resposta para o sub-segmento (2)
- sufixo1 -> é o melhor segmento que está dentro da parte (1) 
e termina exatamente na linha de divisão.
- prefixo2 -> é o melhor segmento que está dentro da parte (2) 
e começa exatamente na linha de divisão.

Exemplo:
[ 4, -1,  2,  5, | -3,  6,  1, -10 ]
seg1 = 10, seg2 = 7, sufixo = 10, prefixo2 = 4
seg = (10, 7, 10 + 4) = 14.

Obs.: Você pode pensar que a resposta pode ser apenas max(seg1, seg2). Porém, como
no exemplo anterior, podemos melhorar a soma partir da travessia da divisória, o 
termo "sufixo1 + prefixo2" no max testa esse caso.

Podemos encontrar os melhores prefixos e sufixos de um nó de forma recursiva

prefix = (prefix1, sum1 + prefixo2)
sufixo = (sufixo2, sum2 + sufixo1)

(1) -> Filho da Esquerda, (2) -> Filho da Direita
*/