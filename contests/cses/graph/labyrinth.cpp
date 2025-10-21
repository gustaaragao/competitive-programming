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
const tuple<int, int, char> mov[4] = {
    {-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}
};

int n, m;
char grid[MAX][MAX], directions[MAX][MAX];
int dist[MAX][MAX];
pi parent[MAX][MAX];

bool valid(int i, int j) {
    return i>=0 and j>=0 and i<n and j<m 
            and (dist[i][j] == -1) and (grid[i][j] != '#'); 
}

void bfs(pi s) {
    queue<pi> q; q.push(s); 
    dist[s.ff][s.ss] = 0;
    parent[s.ff][s.ss] = {-1, -1};
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (auto [di, dj, d] : mov) {
            int ni = i + di, nj = j + dj;
            if (valid(ni, nj)) {
                q.push({ni, nj});
                dist[ni][nj] = dist[i][j] + 1;
                parent[ni][nj] = {i, j}; 
                directions[ni][nj] = d;
            }
        }
    }
}

signed main(){
    memset(dist, -1, sizeof(dist));
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    pi a, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') a = {i, j};
            else if (grid[i][j] == 'B') b = {i, j};
        }
    }
    bfs(a);
    if (dist[b.ff][b.ss] == -1) { // Não visitado
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << dist[b.ff][b.ss] << endl;
        vector<char> path;
        for (pi v = b; parent[v.ff][v.ss] != pi{-1, -1}; v = parent[v.ff][v.ss]) {
            path.pb(directions[v.ff][v.ss]);  // movimento que levou do pai a v
        }
        reverse(all(path));
        for (auto x : path) cout << x;
        cout << endl;
    }
}