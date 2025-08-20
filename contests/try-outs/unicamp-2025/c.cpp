#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;

const int INF = 1e9;

signed main(){ _
    int n; cin >> n;
    vector<int> prefix_sum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == '(') {
            prefix_sum[i] = prefix_sum[i-1] + 1;
        } else {
            prefix_sum[i] = prefix_sum[i-1] - 1;
        }
    }
    int ans = 0, menor = INF;
    for (int i = 1; i < n + 1; i++) {
        if (prefix_sum[i] < 0 && prefix_sum[i] < menor) {
            menor = prefix_sum[i];
            ans = i;
        }
    }
    cout << ans << endl;
}