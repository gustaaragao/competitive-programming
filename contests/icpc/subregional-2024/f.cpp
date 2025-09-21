#include <bits/stdc++.h>
using namespace std; 

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
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
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAXN 45

pi p[MAXN];

signed main(){
    FAST_IO

    p[1].ff = 1; p[1].ss = 2;
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        // 1 + (a / b) = (b / b) + (a / b) = (b + a) / b
        p[i].ff = p[i - 1].ff + p[i - 1].ss;
        p[i].ss = p[i - 1].ss;
        // Fazendo o inverso
        swap(p[i].ff, p[i].ss);
    }

    int g = gcd(p[n].ss, p[n].ff);
    int ans = p[n].ff / g;
    cout << ans << endl;
}

/*
p1 = 1 / (1 + 1) = 1 / 2 -> a = 1
p2 = 1 / (1 + 1 / 2) = 1 / (3 / 2) = 2 / 3 -> a = 2
p3 = 1 / (1 + 2 / 3) = 1 / (5 / 3) = 3 / 5 -> a = 3
*/