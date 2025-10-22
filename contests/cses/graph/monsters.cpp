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

const int MAX = 1e3+10;
const tuple<int, int, char> mov[4] = {
    {-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}
};

int n, m;
char grid[MAX][MAX], dir[MAX][MAX];
int dist_person[MAX][MAX], dist_monster[MAX][MAX]; 
pi parent[MAX][MAX];
bool vis[MAX][MAX];

bool valid(int i, int j) {
    return i >= 0 and j >= 0 and i < n and j < m 
            and !vis[i][j] and grid[i][j] != '#';
}

void bfs_ms(vector<pi> ms) {
    queue<pi> q;
    for (auto [i, j] : ms) {
        q.push({i, j});
        vis[i][j] = true;
        dist_monster[i][j] = 0;
    }
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (auto [di, dj, c] : mov) {
            int ni = i + di, nj = j + dj;
            if (valid(ni, nj)) {
                q.push({ni, nj});
                vis[ni][nj] = true;
                dist_monster[ni][nj] = dist_monster[i][j] + 1;
            }
        }
    }
}

pi bfs(pi s) {
    queue<pi> q; q.push(s); 
    vis[s.ff][s.ss] = true;
    dist_person[s.ff][s.ss] = 0;
    parent[s.ff][s.ss] = {-1, -1};
    dir[s.ff][s.ss] = '?';
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        if ((i == 0) or (j == 0) or (i == n-1) or (j == m-1)) {
            return {i, j};
        }
        for (auto [di, dj, c] : mov) {
            int ni = i + di, nj = j + dj;
            if (valid(ni, nj) and (dist_person[i][j] + 1 < dist_monster[ni][nj])) {
                q.push({ni, nj});
                vis[ni][nj] = true;
                dist_person[ni][nj] = dist_person[i][j] + 1;
                dir[ni][nj] = c;
                parent[ni][nj] = {i, j};
            }
        }
    }
    return {-1, -1};
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dist_monster, INF, sizeof(dist_monster));
    cin >> n >> m;
    vector<pi> ms; pi s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') ms.eb(i, j);
            else if (grid[i][j] == 'A') s = {i, j};
        }
    }
    bfs_ms(ms);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << dist_monster[i][j];
    //     }
    //     cout << endl;
    // }
    memset(vis, false, sizeof(vis));
    pi ans = bfs(s);
    if (ans == pi{-1, -1}) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<char> path;
        for (pi v = ans; v != pi{-1, -1}; v = parent[v.ff][v.ss]) {
            path.pb(dir[v.ff][v.ss]);
        }
        reverse(all(path));
        cout << sz(path)-1 << endl;
        for (int i = 1; i < sz(path); i++) {
            cout << path[i];
        }
        cout << endl;
    }
}