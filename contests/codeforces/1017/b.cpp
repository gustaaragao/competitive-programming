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
    while (t--) {
        int n, m, l, r; cin >> n >> m >> l >> r; 

        int l_ans, r_ans;
        if (m <= r) {
            l_ans = 0; 
            r_ans = m;
        } else {
            r_ans = r;
            l_ans = r - m;
        }
        cout << l_ans << " " << r_ans << endl;
    }    

    return 0;
}