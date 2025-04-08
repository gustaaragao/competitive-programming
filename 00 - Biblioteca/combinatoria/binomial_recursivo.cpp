#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define P 1000000007

int binomial(int n, int m) {
	// Complexidade O(2^n)
	if (m == 0 || n  == m) return 1; // casos base: (n 0) = (n n) = 1
	return (binomial(n - 1, m - 1) + binomial(n - 1, m)) % P;
}


int binomial_dp(int n, int m) {
	// Complexidade O(n^2)
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1; // Caso Base (n 0)
		if (i <= m) dp[i][i] = 1; // Caso Base (n n)
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= min(i, m); j++) {
			if (i != j) {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % P;
			}
		}
	}
	return dp[n][m];
}

int main() { _
    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        // cout << binomial(a, b) << endl;
		cout << binomial_dp(a, b) << endl;
    }
    return 0;
}