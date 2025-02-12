#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int n; cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    // Buscar a maior soma dos subintervalos do vetor
    int ans = -INF, soma = 0;
    for (int i = 0; i < n; i++) {
        for (int tam = 1; tam + i <= n; tam++) {
            soma = 0;
            for (int j = 0; j < tam; j++) soma += v[i + j];
            if (soma > ans) ans = soma;
        }
    }

    cout << ans << endl;

    return 0;
}