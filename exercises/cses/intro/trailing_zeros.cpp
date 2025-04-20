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

ll solve(int n) {
    // count the number of 5 in factorization(n)
    if (n == 0) return 0;
    else return (n / 5L) + solve(n / 5L);
}

int main(){ _

    ll n; cin >> n;
    cout << solve(n) << endl;
    
    return 0;
}