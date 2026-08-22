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
vector<bool> vis;
vector<pi> edges;
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

void dfsCut(int v){
    vis[v] = true;

    for(auto u : g[v]){
        if(!vis[u] && capacity[v][u] > 0){
            dfsCut(u);
        }
    }
}

void solve(){
    cin >> n >> m;
    parent.assign(n, -1);
    vis.assign(n, false);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        g[a].pb(b);
        g[b].pb(a);

        capacity[a][b] += 1;
        capacity[b][a] += 1;

        edges.pb({a, b});
    }

    int ans = maxFlow(0, n - 1);
    dfsCut(0);

    cout << ans << endl;

    for(auto[u, v] : edges){
        if(vis[u] != vis[v]){
            cout << u + 1 << " " << v + 1 << endl;
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
