#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    set<string> s;

    for (int i = n - 1; i >= 0; i--) {
        if (!s.count(v[i])) {
            cout << v[i] << endl;
            s.insert(v[i]);
        }
    }

    return 0;
}