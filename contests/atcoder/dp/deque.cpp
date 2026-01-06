#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

const int MAXN = 3e3 + 10;

int n, a[MAXN], dp[MAXN][MAXN];

int solve(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == j) return dp[i][j] = a[i]; // caso trivial [z], só dá para escolher o z
    return dp[i][j] = max(a[i] - solve(i+1, j), a[j] - solve(i, j-1));
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n-1) << endl;
    int i = 0, j = n - 1;
    bool turn = true;
    vector<int> team1, team2;
    while (i <= j) {
        if (i == j) {
            if (turn) team1.push_back(i);
            else team2.push_back(i);
            break;
        }

        if (dp[i][j] == (a[i] - dp[i+1][j])) {
            // Escolheram o i
            if (turn) team1.push_back(i);
            else team2.push_back(i);
            i++;
        } else {
            // Escolheram o j
            if (turn) team1.push_back(j);
            else team2.push_back(j);
            j--;
        }

        turn = !turn;
    }
}
// dp[i][j] -> MAIOR diferença X - Y que obtemos no intervalo [i, j]