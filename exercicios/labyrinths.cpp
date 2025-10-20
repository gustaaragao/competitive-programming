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

const int MAX = 5e2 + 10;
const pi mov[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int n, m;
char grid1[MAX][MAX], grid2[MAX][MAX];
int dist1[MAX][MAX], dist2[MAX][MAX], dist1rev[MAX][MAX], dist2rev[MAX][MAX];
bool match[MAX][MAX], vis[MAX][MAX];

bool valid(int i, int j) {
    return i >= 0 and j >= 0 and i < n and j < m;
}

void dfs(pi v) {
    auto [i, j] = v; vis[i][j] = true;
    for (auto [di, dj] : mov) {
        int ni = i + di, nj = j + dj;        
        if (valid(ni, nj) and !vis[ni][nj] and match[ni][nj]) {
            dfs({ni, nj});
        }
    }
}

void bfs(pi s, const char (&grid)[MAX][MAX], int (&dist)[MAX][MAX]) {
    queue<pi> q; q.push(s); dist[s.ff][s.ss] = 0;
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (auto [di, dj] : mov) {
            int ni = i + di, nj = j + dj;
            if (valid(ni, nj) and (grid[ni][nj] == '.') and (dist[ni][nj] == -1)) {
                q.push({ni, nj});
                dist[ni][nj] = dist[i][j] + 1;
            }
        }
    } 
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dist1, -1, sizeof(dist1));
    memset(dist2, -1, sizeof(dist2));
    memset(dist1rev, -1, sizeof(dist1rev));
    memset(dist2rev, -1, sizeof(dist2rev));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid2[i][j];
        }
    }
    // Rodando BFS de {0, 0}
    bfs({0, 0}, grid1, dist1);
    bfs({0, 0}, grid2, dist2);
    // Rodando BFS de {n-1, m-1}
    bfs({n-1, m-1}, grid1, dist1rev);
    bfs({n-1, m-1}, grid2, dist2rev);

    // Considere u, tal que {0, 0} -> u -> {n-1, m-1}. 
    // O vértice u percente ao caminho mínimo do grid1 e grid2. Logo, temos que 
    //TAMANHO_DO_CAMINHO = (dist de {0, 0} até u) + (dist de {n-1, m-1} até u)
    int l1 = dist1[n-1][m-1], l2 = dist2[n-1][m-1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist1[i][j] == -1 or dist1rev[i][j] == -1 or dist2[i][j] == -1 or dist2rev[i][j] == -1) {
                match[i][j] = false;
                continue;
            }
            bool cond1 = (dist1[i][j] + dist1rev[i][j]) == l1;
            bool cond2 = (dist2[i][j] + dist2rev[i][j]) == l2;
            // Caso o vértice pertença a algum menor caminho dos dois grid, marca ele em match[][]
            match[i][j] = cond1 and cond2 and (grid1[i][j] == '.') and ((grid2[i][j] == '.'));
        }
    }
    if (match[0][0]) dfs({0, 0});
    if (vis[n-1][m-1]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}