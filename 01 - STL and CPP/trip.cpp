#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int k; cin >> k;

    vector<int> a(12);

    for (int i = 0; i < 12; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int acc = 0;

    for (int i = 11; i >= 0; i--) {
        if (k <= 0) break;
        else {
            k -= a[i];
            acc++;
        }
    }

    if (k <= 0) {
        cout << acc << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}