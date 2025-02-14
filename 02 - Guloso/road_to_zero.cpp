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

    int t; cin >> t;
    ll x, y ,a, b; 
    while (t--) {
        cin >> x >> y >> a >> b;
        ll ans = 0;
        // Vamos supor que x <= y.
        if (x > y) swap(x, y); // essa linha conserta a nossa suposicao
        ll ans1 = 0, ans2 = 0;
        // ans1 -> apenas usando o `a`
        ans1 = x*a + y*a;
        // ans2 -> usando o `b` até zerar o `x` e depois usando o `a` em (y - x), vulgo o resto.
        ans2 = x*b + (y-x)*a;
        ans = min(ans1, ans2);
        cout << ans << endl;
    }

    return 0;
}