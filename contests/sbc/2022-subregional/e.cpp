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

#define MAXN 1e6

// flechas[i] armazena a qtd de flechas na altura i
vector<int> flechas(MAXN, 0);

signed main(){
    FAST_IO
    
    int n; cin >> n;
    ll ans = 0; // armazena a quantidade de flechas lançadas
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (flechas[x] == 0) { // Não há flechas na altura x
            ans++; // O Carlinhos precisa lançar uma flecha
            flechas[x-1]++; // A flecha estoura um balão e fica na altura x-1
        } else { // Há flechas na altura x
            flechas[x]--; // Essa flecha estoura o balão da altura x 
            flechas[x-1]++; // A flecha estoura um balão e fica na altura x-1
        }
    }
    cout << ans << endl;
}