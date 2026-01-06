#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, k, l; cin >> n >> m >> k >> l;
    int min_cartas = ((l + k) + m - 1) / m;
    if (min_cartas * m > n) {
        cout << -1 << endl;
    } else {
        cout << min_cartas << endl;
    }
}

/*
n -> qtd de cartas distintas
m -> qtd de amigos
k -> qtd que o Ivan tem
l -> qtd mínima de cartas novas na coleção

Quantas cartas cada pessoa deve entregar?

No total:
- Podemos entregar as L cartas mínimas novas e as K cartas que Ivan já tem
- (L + K) cartas / M amigos = QTD MÍNIMA DE CARTAS QUE CADA AMIGO DEVE DAR (chamamos de X)
     -> Fazer o teto(a / b) = (a + b - 1) / b
Caso X > n, necessariamente dois amigos vão dar cartas iguais
Caso contrário, a resposta é X
*/