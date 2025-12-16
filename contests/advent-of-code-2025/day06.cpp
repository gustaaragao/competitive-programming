#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define sz(x) (int) (x).size()

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int operations = 0;
    vector<string> input;
    string line;
    while (getline(cin, line)) {
        input.push_back(line);
    }
    int n = sz(input), m = sz(input[0]);
    vector<int> numbers(m, -1);
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            if (input[i][j] >= '0' and input[i][j] <= '9') {
                if (numbers[j] == -1) numbers[j] = 0;
                numbers[j] *= 10;
                numbers[j] += (input[i][j] - '0');
            }
        }
    }

    vector<char> ops;
    for (int j = 0; j < m; j++) {
        if (input[n-1][j] == '*' or input[n-1][j] == '+') {
            ops.push_back(input[n-1][j]);
        }
    }

    int i = 0, ans = 0; 
    for (char op : ops) {
        int res = (op == '*') ? 1 : 0;
        while (i < m and numbers[i] != -1) {
            if (op == '*') {
                res *= numbers[i];
            } else {
                res += numbers[i];
            }
            i++;
        }
        ans += res;
        i++;
    }

    cout << ans << endl;
}