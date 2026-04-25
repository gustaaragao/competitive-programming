#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define endl '\n' //<< flush
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cerr << #x << " = " << x << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
const int MOD = 1e9 + 7; // 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 5e4 + 10;

const pi mov[] = {
    {0, 1}, {1, 2}, {2, 3},
    {4, 5}, {5, 6}, {6, 7},
    {0, 4}, {1, 5}, {2, 6}, {3, 7}
};

typedef pair<int, vector<int>> state;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int> ini(8), fim(8);
    for (int i = 0; i < 8; i++) cin >> ini[i];
    for (int i = 0; i < 8; i++) cin >> fim[i];

    // {dist, estado = vector<int, int>}
    priority_queue<state, vector<state>, greater<state>> pq;
    map<vector<int>, int> dist;
    pq.push({0, ini}); dist[ini] = 0;
    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if (cost > dist[cur]) continue;
        for (auto [i, j] : mov) {
            int w = cur[i] + cur[j]; // custo do swap: soma dos valores
            // nxt -> o próximo estado
            vector<int> nxt = cur;
            swap(nxt[i], nxt[j]);
            if (!dist.count(nxt) or (dist[nxt] > cost + w)) {
                dist[nxt] = cost + w;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    cout << dist[fim] << endl;
}