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

const int MAX = 8 + 1;
const pi mov[8] = {
    {-2, -1}, {-1, -2}, {2, -1}, {1, -2}, {-2, 1}, {-1, 2}, {2, 1}, {1, 2},
}; 

int grid[MAX][MAX], vis[MAX][MAX], dist[MAX][MAX];

bool valid(int i, int j) {
    return i >= 0 and j >= 0 and i < 8 and j < 8 and !vis[i][j];
}

void bfs(pi s) {
    queue<pi> q; q.push(s);
    vis[s.ff][s.ss] = true;
    dist[s.ff][s.ss] = 0;
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (auto [di, dj] : mov) {
            int ni = i + di, nj = j + dj;
            if (valid(ni, nj)) {
                q.push({ni, nj});
                vis[ni][nj] = true;
                dist[ni][nj] = dist[i][j] + 1;
            }
        }
    }
}

pi convert(string s) {
    char ci = s[1], cj = s[0]; 
    return {8 - (ci - '0'), (cj - 'a')};
}

void solve() {
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    string s1, s2; cin >> s1 >> s2;
    pi s = convert(s1), e = convert(s2);
    // cout << s.ff << " " << s.ss << endl;
    // cout << e.ff << " " << e.ss << endl;
    bfs(s);
    cout << dist[e.ff][e.ss] << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t0; cin >> t0;
    while (t0--) solve();
}