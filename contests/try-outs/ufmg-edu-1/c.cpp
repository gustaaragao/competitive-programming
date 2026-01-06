#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

const int MAXN = 1e9 + 5;
const pair<int, int> dir[4] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

string wind;
int n, dist[MAXN][MAXN];

pair<int, int> transform_wind(int day) {
    char d = wind[day % n];
    if (d == 'U') return {1, 0};
    else if (d == 'D') return {-1, 0};
    else if (d == 'R') return {0, 1};
    else return {0, -1};
}

bool valid(int i, int j) {
    return i >= 0 and j >= 0 and i <= 1e3 and j <= 1e3;
}

void bfs(pair<int, int> s) {
    queue<pair<int, int>> q; 
    q.push(s); dist[s.ff][s.ss] = 0;
    while (!q.empty()) {
        pair<int, int> v = q.front(); q.pop();
        for (auto [dx, dy] : dir) {
            auto [dx_w, dy_w] = transform_wind(dist[v.ff][v.ss]);
            int nx = v.ff + (dx + dx_w), ny = v.ss + (dy + dy_w);
            if (valid(nx, ny)) {
                dist[nx][ny] = dist[v.ff][v.ss] + 1;
                q.push({nx, ny});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2 >> n; 
    cin >> wind;
    memset(dist, -1, sizeof(dist));
    bfs({x1, y1});
    cout << dist[x2][y2] << endl;
}