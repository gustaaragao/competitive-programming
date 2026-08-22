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

    int n; cin >> n;

    if (n > 1 && n < 4) cout << "NO SOLUTION" << endl;
    else {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) cout << i << " ";
        }
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
