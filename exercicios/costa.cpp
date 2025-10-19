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

pi mov[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
char grid[MAX][MAX]; 
bool vis[MAX][MAX], marked[MAX][MAX];

bool valid(int i, int j) {
    return i>=0 and j>=0 and i<n and j<m 
            and !vis[i][j] and grid[i][j] == '#';
}

bool frontier(int i, int j) {
    // Fora do mapa -> Costa
    if (i < 0 or j < 0 or i >= n or j >= m) return true;
    // Fronteira com Água -> Costa 
    if (grid[i][j] == '.') return true;
    return false;
}

void bfs(pi s) {
    queue<pi> q;
    q.push(s); vis[s.ff][s.ss] = true;
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (auto [di, dj] : mov) {
            int ni = i + di, nj = j + dj;
            // Faz fronteira com a agua ou está na borda?
            if (frontier(ni, nj)) {
                marked[i][j] = true;
            } else if (valid(ni, nj)) { // É solo
                q.push({ni, nj}); vis[ni][nj] = true;
            } 
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#' and !vis[i][j]) {
                bfs({i, j});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (marked[i][j]) ans++;
        }
    }
    cout << ans << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (marked[i][j]) {
    //             cout << "*";
    //         } else {
    //             cout << grid[i][j];
    //         }
    //     }
    //     cout << endl;
    // }
}