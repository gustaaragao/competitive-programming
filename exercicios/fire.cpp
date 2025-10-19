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

int n, m;
char grid[MAX][MAX]; 
bool vis[MAX][MAX]; 
int dist_fire[MAX][MAX], dist_person[MAX][MAX];
vector<pi> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j) {
    return i >= 0 and j >= 0 and i < n and j < m and !vis[i][j] and grid[i][j] != '#';
}

void bfs_multi(vector<pi> fires) {
    queue<pi> q;
    for (auto f : fires) {
        q.push(f);
        vis[f.ff][f.ss] = true;
        dist_fire[f.ff][f.ss] = 0;
    }
    while (!q.empty()) {
        pi v = q.front(); q.pop();
        for (auto u : mov) {
            int new_i = u.ff + v.ff, new_j = u.ss + v.ss;
            if (valid(new_i, new_j)) {
                q.push({new_i, new_j});
                vis[new_i][new_j] = true;
                dist_fire[new_i][new_j] = dist_fire[v.ff][v.ss] + 1;
            }
        }
    } 
}

int bfs(pi s) {
    queue<pi> q;
    q.push(s); 
    vis[s.ff][s.ss] = true;
    dist_person[s.ff][s.ss] = 0;
    while (!q.empty()) {
        pi v = q.front(); q.pop();
        
        for (auto u : mov) {
            int new_i = u.ff + v.ff, new_j = u.ss + v.ss;
            
            // Verifica se escapou (saiu do grid)
            if (new_i < 0 or new_i >= n or new_j < 0 or new_j >= m) {
                return dist_person[v.ff][v.ss] + 1;
            }
            
            // dist_fire[new_i][new_j] checa o tempo que o fogo vai atingir (new_i, new_j)
            // dist_person[v.ff][v.ss]+1 é o instante que estaremos quando vamos para (new_i, new_j)
            if (valid(new_i, new_j) and dist_person[v.ff][v.ss] + 1 < dist_fire[new_i][new_j]) {
                q.push({new_i, new_j}); 
                vis[new_i][new_j] = true;
                dist_person[new_i][new_j] = dist_person[v.ff][v.ss] + 1;
            }
        }
    }
    return -1;
}

void solve() {
    memset(dist_fire, INF, sizeof(dist_fire)); // dist_fire[] = INF
    memset(vis, false, sizeof(vis));
    
    cin >> m >> n;
    pi start;
    vector<pi> fires;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '*') fires.eb(i, j);
            else if (grid[i][j] == '@') start = {i, j};
        }
    }
    // BFS MULTISOURCE PARA ESPALHAR O FOGO
    bfs_multi(fires);
    // BFS SINGLESOURCE PARA CAMINHAR NO MAPA
    memset(vis, false, sizeof(vis));
    int ans = bfs(start);
    if (ans == -1) {
        cout << "IMPOSSIBLE" << endl; 
    } else {
        cout << ans << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t0; cin >> t0;
    while(t0--) solve();
}