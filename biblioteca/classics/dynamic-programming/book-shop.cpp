#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MAXN = 1e3 + 1;
const int MAXW = 1e5 + 1;

int n, x, dp[MAXW], preco[MAXN], v[MAXN];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> preco[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        int preco_atual = preco[i];
        int valor_atual = v[i];
        for (int j = x; j >= preco_atual; j--) {
            dp[j] = max(dp[j], dp[j - preco_atual] + valor_atual);
        }
    }

    cout << dp[x] << endl;
}
