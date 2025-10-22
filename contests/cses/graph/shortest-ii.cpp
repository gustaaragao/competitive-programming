#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define int long long

typedef pair<int, int> pi;

const int INF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 5e2 + 10;

int n, m, q;
int w[MAX][MAX], dist[MAX][MAX];

void initialize() {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF ;
            }
        }
    }
}
void floyd_warshall() {
    for (int k = 0 ; k < n ; k++) {
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]) ;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> q;
    initialize();
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        w[a][b] = c;
        dist[a][b] = min(dist[a][b], c);
        w[b][a] = c;
        dist[b][a] = min(dist[b][a], c);
    }
    floyd_warshall();
    while (q--) {
        int a, b; cin >> a >> b; a--, b--;
        if (dist[a][b] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[a][b] << endl;
        }
    }
}