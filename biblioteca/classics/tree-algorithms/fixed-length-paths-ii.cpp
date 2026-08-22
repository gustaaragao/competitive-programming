#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
struct FenwickTree
{
    vector<int> BIT;
    int n;
    FenwickTree(int n) : n(n + 1), BIT(n + 5) {}

    void add(int i, int val)
    {
        for (++i; i <= n; i += i & -i)
            BIT[i] += val;
    }
    void set(int i)
    {
        for (++i; i <= n; i += i & -i)
            BIT[i] = 0;
    }
    int pre(int i)
    {
        int sum = 0;
        for (++i; i; i -= i & -i)
            sum += BIT[i];
        return sum;
    }
    int query(int l, int r)
    {
        return pre(r) - pre(l - 1);
    }
};
const int N = 2e5 + 5;
vector<int> adj[N];
long long ans;
int sz[N];
FenwickTree cnt(N);
bool removed[N];
int k1, k2, mx;
long long depth[N];
void dfsSz(int u, int p)
{
    sz[u] = 1;
    for (auto v : adj[u])
    {
        if (v == p || removed[v])
            continue;
        dfsSz(v, u);
        sz[u] += sz[v];
    }
};
int get(int u, int p, int n)
{
    for (auto v : adj[u])
    {
        if (v == p || removed[v])
            continue;
        if (2 * sz[v] > n)
            return get(v, u, n);
    }
    return u;
}
int dfs(int u, int p, int d)
{
    depth[d]++;
    int ret = d;
    for (auto v : adj[u])
    {
        if (v == p || removed[v] || k2 < d + 1)
            continue;
        ret = max(ret, dfs(v, u, d + 1));
    }
    return ret;
}
void decomp(int u)
{
    dfsSz(u, -1);
    int root = get(u, -1, sz[u]);
    removed[root] = 1;
    cnt.add(0, 1);
    mx = 0;
    for (auto v : adj[root])
    {
        if (!removed[v])
        {
            int tot = dfs(v, root, 1);
            for (int i = tot; i >= 1; i--)
            {
                if (depth[i] == 0)
                    continue;
                int l = max(0, k1 - i);
                int r = k2 - i;
                ans += depth[i] * cnt.query(l, r);
            }
            for (int i = tot; i >= 1; i--)
            {
                cnt.add(i, depth[i]);
                depth[i] = 0;
            }
        }
    }
    for (int i = 0; i <= sz[u]; i++)
        cnt.set(i), depth[i] = 0;
    for (auto v : adj[root])
    {
        if (!removed[v])
            decomp(v);
    }
}
void Solve()
{
    int n;
    cin >> n >> k1 >> k2;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    decomp(0);
    cout << ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef CPH
#elif defined(ONLINE_JUDGE)
    // freopen("IN.in", "r", stdin);
    // freopen("OUT.out", "w", stdout);
#else
    freopen("IN.txt", "r", stdin);
    freopen("OUT.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << TC++ << ": ";
        Solve();
    }
    return 0;
}
