#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define sz(x) (int) (x).size()

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int operations = 0;
    vector<string> input;
    string in;
    while (cin >> in) {
        if (in == "*" or in == "+") operations++;
        cout << sz(in) << endl;
        input.push_back(in);
    }
    int ans = 0LL;
    for (int i = 0; i < operations; i++) {
        vector<int> numbers;
        int j = i;
        while (true) {
            if (input[j] == "*" or input[j] == "+") {
                int res;
                if (input[j] == "*") {
                    res = 1;
                    for (auto x : numbers) {
                        res *= x;
                    }
                } else {
                    res = 0;
                    for (auto x : numbers) {
                        res += x;
                    }
                }
                ans += res;
                break;
            } else {
                numbers.push_back(atoll(input[j].c_str()));
            }
            j += operations;
        }
        numbers.clear();
    }
    cout << ans << endl;
}