#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const ll P = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        vector<ll> a(n); for (auto &x : a) cin >> x;
        vector<ll> k(q); for (auto &x : k) cin >> x;
        // Vetor h com as alturas de cada degrau --> Prefix-sums
        vector<ll> h(n+1); h[0] = 0;
        for (int i = 0; i < n; i++) h[i+1] = a[i] + h[i];
        
        // Vetor max_a é da seguinte maneira: max_a[i] = max({a1, a2, ..., ai}) --> Prefix-maximums
        vector<ll> max_a(n); max_a[0] = a[0];
        for (int i = 1; i < n; i++) max_a[i] = max(a[i], max_a[i-1]);


        // o objetivo é encontrar o maior i tal que max_a[i] <= k --> Busca binária
        for (auto length : k) {
            // Queremos maximar o i, ou seja, é melhor usarmos upper_bound
            // upper_bound --> retorna um iterador para o primeiro elemento MAIOR que o target (> target)
            // lower_bound --> retorna um iterador para o primeiro elemento MENOR que o target (< target)
            int id = upper_bound(all(max_a), length) - max_a.begin();
            cout << h[id] << " ";
        }
        
        cout << endl;
    }    

    return 0;
}