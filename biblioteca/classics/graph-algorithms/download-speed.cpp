// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cerr << #x << " = " << x << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 4e18;
const int MAXN = 500 + 5;
const int MAX = 1e9 + 5;

int n, m;
vector<int> g[MAXN];
vector<int> parent;
int capacity[MAXN][MAXN];

int bfs(int s, int t){
    fill(all(parent), - 1);

    queue<pi> q;
    parent[s] = -2;

    q.push({s, INF});

    while(!q.empty()){
        auto[u, flow] = q.front();
        q.pop();

        for(int v : g[u]){
            if(parent[v] == -1 && capacity[u][v] > 0){
                parent[v] = u;

                int newFlow = min(flow, capacity[u][v]);

                if(v == t){
                    return newFlow;
                }

                q.push({v, newFlow});
            }
        }
    }

    return 0;
}

int maxFlow(int s, int t){
    int flow = 0;

    while(true){
        int bottleneck = bfs(s, t);

        if(bottleneck == 0){
            break;
        }

        flow += bottleneck;

        int cur = t;

        while(cur != s){
            int prev = parent[cur];

            capacity[prev][cur] -= bottleneck;
            capacity[cur][prev] += bottleneck;

            cur = prev;
        }
    }

    return flow;
}

void solve(){
    cin >> n >> m;
    parent.assign(n, -1);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        a--;
        b--;

        g[a].pb(b);
        g[b].pb(a);

        capacity[a][b] += c;
    }

    cout << maxFlow(0, n - 1) << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
