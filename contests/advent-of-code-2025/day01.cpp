#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string in;
    int pos = 50, ans = 0;
    while (cin >> in) {
        char op = in[0];
        int x = stoi(in.substr(1));
        if (op == 'L') {
            while (x--) {
                pos = (pos - 1 + 100) % 100;
                if (pos == 0) ans++;
            }
        } else { // op == 'R'
            while (x--) {
                pos = (pos + 1 + 100) % 100;
                if (pos == 0) ans++;
            }
        }
    }
    cout << ans << endl;
}
