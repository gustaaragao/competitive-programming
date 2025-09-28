#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAX_N 1000000

ll dp[MAX_N + 1];

ll solve(ll k) {
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= 6 && i - j >= 0; j++) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    return dp[k];
}

signed main(){ _
    ll n; cin >> n;

    dp[0] = 1;

    cout << solve(n) << endl;
}

/* Lógica
Nosso objetivo é descobrir de quantas maneiras podemos chegar a um valor K somando x que pertencem a (1, 2, 3, 4, 5, 6).

solve(k) = solve(k - 1) + solve(k - 2) + solve(k - 3) + solve(k - 4) + solve(k - 5) + solve(k - 6)
= sum{i = 1 até 6, k - i >= 0}{solve(k - i)} --> Nossa recorrência é essa aqui

a função solve(k) retorna o número de vezes que podemos chegar em solve(k)
--------
Para k = 3
solve(3) = solve(2) + solve(1) + solve(0) # 0 -> Quantas maneiras há de fazer a soma 0? Apenas uma, fazer nada.

Precisamos resolver solve(1) e solve(2):
- solve(1) = solve(0) = 1
- solve(2) = solve(1) + solve(0) = 1 + 1 = 2

Logo, solve(3) = 2 + 1 + 1 = 4!
*/