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

bool cmp(ii a, ii b) {
    if (a.s != b.s) return a.s < b.s;
    return a.f < b.f; // desempate do a.s == b.s
}

int main(){ _

    int n; cin >> n;
    vector<ii> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].f >> v[i].s;
    sort(v.begin(), v.end(), cmp);

    int ans = 0, fim_anterior = -1;
    for (int i = 0; i < n; i++) {
        if (v[i].f >= fim_anterior) {
            ans++;
            fim_anterior = v[i].s;
        }
    }

    cout << ans << endl;

    return 0;
}