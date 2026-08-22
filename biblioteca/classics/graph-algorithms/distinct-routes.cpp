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
const int MAXN = 1000 + 5;

int n, m;
vector<int> g[MAXN];
vector<int> parent;
int capacity[MAXN][MAXN];
int capacityCopy[MAXN][MAXN];
int used[MAXN][MAXN];

int bfs(int s, int t){
    fill(all(parent), -1);

    queue<pi> q;
    parent[s] = -2;

    q.push({s, INF});

    while(!q.empty()){
        auto [u, flow] = q.front();
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

vector<int> getPath(){
    vector<int> path;

    int cur = 0;
    path.pb(cur);

    while(cur != n - 1){
        for(int v : g[cur]){
            if(used[cur][v] > 0){
                used[cur][v]--;
                cur = v;
                path.pb(cur);
                break;
            }
        }
    }
    return path;
}

void solve(){
    cin >> n >> m;
    parent.assign(n, -1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        g[a].pb(b);
        g[b].pb(a);

        capacity[a][b] = 1;
        capacityCopy[a][b] = 1;

    }


    int k = maxFlow(0, n - 1);

      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           used[i][j] = capacityCopy[i][j] - capacity[i][j];
        }
    }

    cout << k << endl;

    for(int i = 0; i < k; i++){
        vector<int> path = getPath();

        cout << path.size() << endl;

        for(int v : path){
            cout << v + 1 << " ";
        }

        cout << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
