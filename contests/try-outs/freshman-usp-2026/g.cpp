#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define endl '\n' //<< flush
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cerr << #x << " = " << x << endl
#define pdbg(x) cerr << #x << " = " << x.ff << "," << x.ss << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
const ld EPS = 1e-9;
const int MOD = 1e9 + 7; // 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 1e2+10;

int n, m, x, y, dp0[35][35], dp1[35][35], dp2[35][35]; 

bool valid(int i, int j) {
    return i >= 0 and j >= 0 and i < n and j < m;
}

// (i, j) posso ter vindo (i-1, j) vindo por cima
// (i, j) posso ter vindo de (i, j-1) vindo pela esquerda
int rec(int i, int j, int si, int sj, int dp[35][35]) {
    if (!valid(i, j)) return 0;
    
    if (dp[i][j] != -1) return dp[i][j];
    
    if (i == si and j == sj) return dp[i][j] = 1;
    
    return dp[i][j] = rec(i-1, j, si, sj, dp) + rec(i, j-1, si, sj, dp);
}

// (i, j) posso ter vindo (i+1, j) vindo por baixo
// (i, j) posso ter vindo de (i, j+1) vindo pela direita
int rec2(int i, int j, int si, int sj, int dp[35][35]) {
    if (!valid(i, j)) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (i == si and j == sj) return dp[i][j] = 1;

    return dp[i][j] = rec2(i+1, j, si, sj, dp) + rec2(i, j+1, si, sj, dp);
}

void solve() {
    cin >> n >> m >> x >> y;
    memset(dp0, -1, sizeof(dp0));
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    int total = rec(n-1, m-1, 0, 0, dp0);
    int ini_monstro = rec(x-1, y-1, 0, 0, dp1);
    int fim_monstro = rec2(x-1, y-1, n-1, m-1, dp2);

    cout << total - (fim_monstro * ini_monstro) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout.precision(10); cout.setf(ios::fixed);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}