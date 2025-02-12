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

bool cmp (pair<int, int> a, pair<int, int> b) {
    if (a.s != b.s) return a.s < b.s;
    else return a.f < b.f; // desempate para quando a.s == b.s
}

int main(){ _
    int n; cin >> n;
    
    vector<ii> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].f; cin >> v[i].s;
    }

    sort(v.begin(), v.end(), cmp);

    int ans = 0, fim = -1;
    for (int i = 0; i < n; i++) {
        if (v[i].f > fim) {
            ans++;
            fim = v[i].s;
        }
    }

    cout << ans << endl;

    return 0;
}