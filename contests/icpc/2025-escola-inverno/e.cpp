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

int main(){ _

    int l, r; cin >> l >> r;
    if (l >= 0) cout << "Y" << endl;
    else if (l < 0 && r >= 0) cout << "Y" << endl;
    else {
        int dist = abs(r) - abs(l) - 1;
        if (dist % 2 == 0) cout << "Y" << endl;
        else cout << "N" << endl;
    } 

    return 0;
}