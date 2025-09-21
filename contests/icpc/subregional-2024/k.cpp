#include <bits/stdc++.h>
using namespace std; 

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
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
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAXN 100005

int values[MAXN];
int choose[MAXN];

signed main(){
    FAST_IO

    memset(choose, -1, sizeof(choose));

    int n; cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> values[i];
        sum += values[i];
    }
    if (sum % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }
    sum /= 2;
    vector<bool> dp(sum+1);
    dp[0] = true; choose[0] = -1;
    for (int i = 0; i < n; i++) {
        int v = values[i];
        for (int s = sum; s - v >= 0; s--) {
            if (dp[s - v] && !dp[s]) {
                choose[s] = i;
                dp[s] = true;
            }
        }
    }

    if (!dp[sum]) {
        cout << -1 << endl; 
        return 0;
    }

    vector<int> alice, bob;
    vector<bool> visited(n, false);
    int cur = choose[sum];
    while (cur != -1) {
        alice.pb(values[cur]);
        sum -= values[cur];
        visited[cur] = true;
        cur = choose[sum];
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bob.pb(values[i]);
        }
    }
    
    int sum_alice = 0, sum_bob = 0;
    while (!alice.empty() || !bob.empty()) {
        if (sum_alice <= sum_bob) {
            cout << alice.back() << " ";
            sum_alice += alice.back();
            alice.pop_back();
        } else {
            cout << bob.back() << " ";
            sum_bob += bob.back();
            bob.pop_back();
        }
    }

    cout << endl;
}