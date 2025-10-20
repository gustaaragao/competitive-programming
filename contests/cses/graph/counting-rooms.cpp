#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e3 + 10;
const pi mov[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
char grid[MAX][MAX];
bool vis[MAX][MAX];

bool valid(int i, int j) {
    return i>=0 and j>=0 and i<n and j<m 
            and !vis[i][j] and grid[i][j] == '.';
}

void dfs(pi v) {
    auto [i, j] = v;
    vis[i][j] = true;
    for (auto [di, dj] : mov) {
        int ni = i + di, nj = j + dj;
        if (valid(ni, nj)) {
            vis[ni][nj] = true;
            dfs({ni, nj});
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] and grid[i][j] == '.') {
                ans++;
                dfs({i, j});
            }
        }
    }
    cout << ans << endl;
}