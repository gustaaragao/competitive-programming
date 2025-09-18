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

// n -> contagem de 0s
// m -> contagem de 1s
// balance = max(n - m, m - n) <= k;
void solve(){
    int n, m, k; cin >> n >> m >> k;
    // Se abs(n - m) > k -> a string final não é válida
    if (abs(n - m) > k) {
        cout << -1 << endl;
        return;
    }
    // Se max(n, m) < k -> O maior balance que uma substring pode obter é max(n, m).
    // Se nem esse maior valor for suficiente para atingir k, não podemos nem sequer construir uma solução.
    if (max(n, m) < k) {
        cout << -1 << endl;
        return;
    }
    ll cnt0 = 0, cnt1 = 0;
    string ans; ans.reserve(n + m);
    if (n >= m) {
        // qtd de 0s em s >= qtd de 1s em s
        for (int i = 0; i < k; i++) {
            // Já montamos nossa solução -> a substring ans[0...k-1] resolve o problema
            ans += "0";
            cnt0++;
        }
        // Agora precisamos colocar 1's e 0's alternando -> Isso impede que crie algum substring com balance > k
        bool one = true;
        while (cnt0 != n) {
            if (one) {
                ans += "1";
                cnt1++;
            } else {
                ans += "0";
                cnt0++;
            }
            one = !one;
        }
        while (cnt1 != m) {
            ans += "1";
            cnt1++;
        }
    } else {
        // Solução análoga ao caso anterior
        // qtd de 0s em s < qtd de 1s em s
        for (int i = 0; i < k; i++) {
            ans += "1";
            cnt1++;
        }
        // Agora precisamos colocar 1's e 0's alternando -> Isso impede que crie algum substring com balance > k
        bool zero = true;
        while (cnt1 != m) {
            if (zero) {
                ans += "0";
                cnt0++;
            } else {
                ans += "1";
                cnt1++;
            }
            zero = !zero;
        }
        while (cnt0 != n) {
            ans += "0";
            cnt0++;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}