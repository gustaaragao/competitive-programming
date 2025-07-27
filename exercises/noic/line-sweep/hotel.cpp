#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define ENTRADA 0
#define SAIDA 1

int main() { _

    int n; cin >> n;

    vector<pi> ev;

    for (int i = 0; i < n; i++) {
        int e, s; cin >> e >> s;
        ev.pb({e, ENTRADA});
        ev.pb({s, SAIDA});
    }

    sort(all(ev));

    int acc = 0, ans = -1;
    for (auto const [tempo, tipo] : ev) {
        if (tipo == ENTRADA) acc++;
        else acc--;
        ans = max(ans, acc);
    }

    cout << ans << endl;

    return 0;
}