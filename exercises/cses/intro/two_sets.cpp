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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    ll n; cin >> n;

    ll total_sum = (n * (n + 1L)) / 2;
    if (total_sum % 2 != 0) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        vector<int> a, b;
        vector<bool> visited(n + 1, false);
        ll sum_a = 0, current = n;
        while (sum_a < total_sum / 2) {
            ll remain = total_sum / 2 - sum_a;
            if (remain > current) {
                a.pb(current);
                sum_a += current;
                visited[current] = true;
                current--;
            } else {
                a.pb(remain);
                visited[remain] = true;
                break;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) b.pb(i);
        }

        // print a
        sort(all(a));
        cout << a.size() << endl;
        for (auto x : a) cout << x << " ";
        cout << endl;
        // print b
        cout << b.size() << endl;
        for (auto x : b) cout << x << " ";
        cout << endl;
    }

    return 0;
}