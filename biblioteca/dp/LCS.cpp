#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MAXN = 3e3 + 10;
string s, t;
int dp[MAXN][MAXN];
int lcs(int n, int m) { // n, m -> tamanho das strings
    if (n == 0 or m == 0) return dp[n][m] = 0;
    if (dp[n][m] != -1) return dp[n][m];
    if (s[n-1] == t[m-1]) { // Faz um match
        return dp[n][m] = 1 + lcs(n-1, m-1);
    } else { // s[n-1] != s[m-1] -> Não fez um match
        return dp[n][m] = max(lcs(n-1, m), lcs(n, m-1));
    }
}
string get_lcs(int n, int m) {
    string str = "";
    int i = n, j = m;
    while (i > 0 and j > 0) {
        if (s[i-1] == t[j-1]) {
            str += s[i-1];
            i--, j--;
        } else {
            // Caminhamos para a célula de maior valor
            if (dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(str.begin(), str.end());
    return str;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> s >> t;
    int n = (int) s.size(), m = (int) t.size();
    lcs(n, m);
    cout << get_lcs(n, m) << endl;
}
