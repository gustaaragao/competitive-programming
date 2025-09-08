#include <bits/stdc++.h>
using namespace std; 

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
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

signed main(){
    FAST_IO

    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    int k, l; cin >> k >> l;
    // sum_k -> soma dos K valores
    // sum_l -> soma dos L valores (Soma ótima)
    ll sum_k = 0, sum_l = 0;
    // s -> L maiores valores do conjunto K | t -> (K - L) valores restantes
    multiset<int> s, t;
    // A função relax() serve para manter |s| = L e de |t| = K - L
    auto relax = [&] () {
        while (s.size() > l) {
            // Conjunto s tem tamanho maior que o máximo L
            auto it = s.begin(); // remova o menor valor do conjunto s
            sum_l -= *it;        // atualize a soma
            t.insert(*it);       // adicione esse valor no conjunto t
            s.erase(it);         // remove o valor s
        }
        while (s.size() < l && !t.empty()) {
            // Conjunto s tem tamanho menor que o L e Conjunto t não está vazio
            auto it = t.end(); // remova o maior valor do conjunto t
            it--;
            sum_l += *it;        // atualize a soma
            s.insert(*it);       // adicione esse valor no conjunto s
            t.erase(it);         // remove o valor t
        }
    };
    // Insere no conjunto s
    auto insert = [&] (int i) {
        sum_l += b[i];
        s.insert(b[i]);
        relax();
    };
    // Remove do conjunto s ou t
    auto remove = [&] (int i) {
        if (s.count(b[i])) {
            s.erase(b[i]);
            sum_l -= b[i];
        } else {
            t.erase(b[i]);
        }
        relax();
    };
    
    // Primeiro Caso: Prefixo = K e Sufixo = 0
    for (int i = 0; i < k; i++) {
        sum_k += a[i];
        insert(i);
    }
    ll ans = sum_k + sum_l;
    for (int i = k - 1, j = 1; i >= 0; i--, j++) {
        // Remove a carta i
        sum_k -= a[i];
        remove(i);
        // Adiciona a carta n - j
        sum_k += a[n-j];
        insert(n - j);

        ans = max(ans, sum_k + sum_l);
    } 
    cout << ans << endl;
}