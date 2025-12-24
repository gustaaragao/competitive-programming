#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

// dp[i] -> MAIOR CUSTO da subsequencia não-decrescente que termina em i
// solucao = soma(c[]) - max(dp[])

const int MAXN = 8e3 + 10;

int a[MAXN], c[MAXN], dp[MAXN];
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    
    int total = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = c[i];
        total += c[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i]) {
                dp[i] = max(dp[i], dp[j] + c[i]);
            }
        }
    }

    int best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, dp[i]);
    }

    cout << total - best << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve();
}
