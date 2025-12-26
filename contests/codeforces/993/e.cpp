#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

/*
Note que k^32 >= 2^32 > 10^9 --> 1 <= n <= 32 (Podemos brutar todos os n)

Sabemos que y = k^n * x, então para x temos as restrições:

- l1 <= x <= r1
- l2 / k^n <= x <= r2 / k^n
- Como x é inteiro, teto(l2 / k^n) <= x <= piso(r2 / k^2)

--> teto(x / y) = (x + y - 1) / y

Então, max(l1, l2 / k^n) <= x <= min(r1, r2 / k^n)

O tamanho do intervalo é igual ao número de pares possíveis
*/

void solve() {
    int k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
    int kn = 1, ans = 0;
    for (int n = 0; n <= 32 and kn <= 1e9; n++) {
        int l = max(l1, (l2 + kn - 1) / kn), r = min(r1, r2 / kn);
        ans += max(0LL, r - l + 1);
        kn *= k; // k^n
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}