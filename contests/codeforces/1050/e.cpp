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
typedef tuple<int, int, int> ti;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, k;

void solve() {
    vector<ll> a(n), cnt(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    // É possível dividir i para cada pacote k de forma igual?
    for (int i = 0; i <= n; i++) {
        if (cnt[i] % k != 0) {
            cout << 0 << endl;
            return;
        }
    }
    
    ll ans = 0;
    // Sliding Windows
    vector<ll> c(n+1);
    for (int l = 0, r = 0; r >= l && r < n; r++) {
        c[a[r]]++;
        while (c[a[r]] > (cnt[a[r]] / k)) {
            // Condição para Contrair a Sliding Window
            c[a[l]]--;
            l++;
        } ans += r - l + 1;
       
    }
    cout << ans << endl;
}

signed main(){
    FAST_IO

    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        solve();
    }
}

/* Explicação:
Considere cnt[i] o número de ocorrências de i em a[].

Como temos k multiset, cada multiset deve ter cnt[i] / k ocorrências de i.

Vamos considerar uma subarray a[l...r], t.q c[i] é o número de ocorrências de i na subarray a[l...r]
    - O enunciado fala que todos os elementos de a[l...r] precisam ir para a multiset 1.
    - Note que a[l...r] para um valor i pode ter c[i] = cnt[i] / k, mas também pode ter c[i] < cnt[i] / k,
    ou seja, todos os valores necessários ou um pouco menos que o suficiente. Porém, jamais deve ter mais!

Logo, uma subarray a[l...r] é awesome 
<=> 
Para todo i de a[l...r] que aparece c[i] vezes vale a seguinte desigualdade: c[i] <= cnt[i] / k.

Logo, o problema é contar o número de subarray que vale a propriedade descrita anteriormente. :)
*/