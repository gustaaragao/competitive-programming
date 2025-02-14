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

    int s; cin >> s;
    vector<ll> q(s), n(s);
    for (int i = 0; i < s; i++) cin >> q[i];    
    for (int i = 0; i < s; i++) cin >> n[i];
    
    sort(n.begin(), n.end(), greater<>());

    int ans = 0, j = 0;
    
    cout << ans << endl;

    return 0;
}