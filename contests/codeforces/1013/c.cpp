#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const ll P = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n % 2 == 0) cout << -1 << endl;
        else {
            vector<int> ans(n);
            ans[n - 1] = n;
            int shift = 1;
            for (int i = n - 1; i > 0; i--) {
                ans[((((i - 1) - shift) % n) + n) % n] = i; // o "%" mantem o sinal do operando
                shift++;
            }
            for (int i = 0; i< n; i++) cout << ans[i] << " ";
            cout << endl;
        }
    }

    return 0;
}