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

    ll n; cin >> n;
    cout << n << " ";
    while (n != 1) {
        if (n % 2 == 0) n = n / 2;
        else n = 3*n + 1;
        cout << n << " ";
    }
    cout << endl;

    return 0;
}