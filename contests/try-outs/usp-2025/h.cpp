#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;

signed main(){ _
    ll w, k; cin >> w >> k;
    ll ans = 2 * k - w;
    cout << ans << endl;
}
/*
W -> mestre
K -> aluno

(x - W) = 2*(x - K)
x - W = 2x - 2K
x = 2K - W
*/