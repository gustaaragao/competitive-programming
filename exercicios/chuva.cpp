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
const pi mov[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
char grid[MAX][MAX];
bool vis[MAX][MAX];

bool valid(int i, int j) {
    return i >= 0 and j >= 0 and i < n and j < m and !vis[i][j] and grid[i][j] == '.';
}

bool drain(int i, int j) {
    if ((i-1 >= 0) and (grid[i-1][j] == 'o')) 
        return true;
    if ((j-1 >= 0) and (i+1 < n) and (grid[i][j-1] == 'o') and (grid[i+1][j-1] == '#'))
        return true;
    if ((j+1 < m) and (i+1 < n) and (grid[i][j+1] == 'o') and (grid[i+1][j+1] == '#'))
        return true;
    return false;
}

void bfs(pi s) {
    queue<pi> q; q.push(s);
    vis[s.ff][s.ss] = true;
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (auto [di, dj] : mov) {
            int ni = i + di, nj = j + dj;
            if (valid(ni, nj) and drain(ni, nj)) {
                q.push({ni, nj});
                vis[ni][nj] = true;
                grid[ni][nj] = 'o';
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    pi s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'o') {
                s = {i, j};
            }
        }
    }
    bfs(s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // if (grid[i][j] == '#') cout << '#';
            // else if (vis[i][j]) cout << "o";
            // else cout << ".";
            cout << grid[i][j];
        }
        cout << endl;
    }
}