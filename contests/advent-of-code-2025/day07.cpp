#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define sz(x) (int) (x).size()

int n, m;

bool valid(int i, int j) {
    return i>=0 and j>=0 and i < n and j < m;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<string> input;
    string line;
    while (getline(cin, line)) {
        input.push_back(line);
    }
    n = sz(input), m = sz(input[0]);
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (input[i][j] == '|' or input[i][j] == 'S') {
                if (valid(i+1, j)) {
                    if (input[i+1][j] == '.') {
                        input[i+1][j] = '|';
                    } else if (input[i+1][j] == '^') {
                        if (valid(i+1, j-1) and input[i+1][j-1] == '.') {
                            input[i+1][j-1] = '|';
                        }
                        if (valid(i+1, j+1) and input[i+1][j+1] == '.') {
                            input[i+1][j+1] = '|';
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < m; j++) {
        ans += dp[n-1][j];
    }
    cout << ans << endl;
}