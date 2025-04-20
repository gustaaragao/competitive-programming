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

const ll P = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll power(ll base, ll expo, ll mod) {
    ll ans = 1;
    while(expo) {
        if(expo & 1LL) {
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        expo >>= 1LL;
    }
    return ans;
}

int main(){ _
    ll n; cin >> n; 
    cout << power(2, n, P) << endl;
    return 0;
}