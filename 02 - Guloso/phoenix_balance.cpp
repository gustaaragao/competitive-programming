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

    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;

        vector<int> v(n);
        v[0] = 2, v[1] = 4;
        for (int i = 2; i < n; i++) v[i] = 2 * v[i - 1];

        ll a = 0, b = 0;
        int metade = n / 2;

        a += v[n - 1];
        for (int i = 0; i < metade - 1; i++) a += v[i];
        for (int i = metade - 1; i < n - 1; i++) b += v[i];

        cout << abs(a - b) << endl;
    }

    /*
    A estratégia gulosa é:
    - O "a" começa com o maior valor possível (v[n - 1])
    - "a" e "b" possuem a mesma quantidade de números
    - "a" recebe (n /2) - 1 menores do conjunto
    - "b" recebe os maiores números restantes
    */

    return 0;
}