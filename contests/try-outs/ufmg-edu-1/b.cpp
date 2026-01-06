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

void solve() {
    int k, m; cin >> k >> m;
    deque<int> num;
    while (k > 0) {
        num.push_back(k % 10);
        k = k / 10;
    }
    reverse(all(num));
    // for (auto x : num) cout << x << " ";
    // cout << endl;

    while (m--) { // 100 vezes
        int pos = -1;
        for (int i = 0; i < (int) num.size(); i++) { // 18 vezes
            // cout << num[i] << " ";
            if (num[i] >= 5) {
                pos = i;
            }
        }
        // cout << endl;
        if (pos != -1) {
            // dbg(pos);
            for (int i = pos+1; i < (int) num.size(); i++) {
                num[i] = num[i] * 2;
            }
            num[pos] = (num[pos] * 2) % 10;
            if (pos == 0) {
                num.push_front(1);
            } else {
                num.insert(num.begin() + pos, 1);
            }
        } else {
            for (int i = 0; i < (int) num.size(); i++) {
                num[i] = num[i] * 2;
            }
        }
    }

    for (auto x : num) cout << x;
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}