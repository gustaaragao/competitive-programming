#include <bits/stdc++.h>

#define nl '\n'
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vl vector<ll>
#define vvl vector<vl>
#define vll vector<pll>
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) x.size())

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_multiset;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e16;
const ll P = 13;
const ll M = 1e9 + 7;
const ll MAX = 5e3 + 5;
const ll MAXN = 3e5 + 5;
const ll MAXT = 1e2 + 5;
const ll MAXK = 1e6 + 5;
const ll K = 26;

ll n, m, k, q, x, y, s;

vector<vl> g;
//vl vis;
//vector<vector<pll>> g;

//vector<ll> primes;
//ll is_prime[MAXN];
vector<ll> ans;

struct Vertex {
    int next[K];
    int go[K];
    int link = -1;
    int p = -1;
    char pch;
    vector<int> output;
    int cnt = 0;

    Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const &s, int id) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].output.pb(id);
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0) {
            t[v].link = 0;
        } else {
            t[v].link = go(get_link(t[v].p), t[v].pch);
        }
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch-'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] == -1) {
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        } else {
            t[v].go[c] = t[v].next[c];
        }
    }
    return t[v].go[c];
}

void dfs(ll u, ll p = -1) {
    for (ll v : g[u]) {
        dfs(v);
        t[u].cnt += t[v].cnt;
    }
    for (ll i : t[u].output) {
        ans[i] = t[u].cnt;
    }
}

void solve(ll tt, ll ti) {
    string s; cin >> s;
    n = s.size();
    cin >> k;

    vector<string> pat(k);
    for (ll i = 0; i < k; i++) {
        string t; cin >> t;
        pat[i] = t;
        add_string(t, i);
    }

    queue<ll> q;
    q.push(0);
    t[0].link = 0;

    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll c = 0; c < K; c++) {
            if (t[v].next[c] != -1) {
                t[t[v].next[c]].link = v == 0 ? 0 : go(t[v].link, (char) (c + 'a'));
                q.push(t[v].next[c]);
            }
        }
    }

    g.assign(t.size(), vl());
    for (ll i = 1; i < t.size(); i++) {
        g[t[i].link].pb(i);
    }

    int v = 0;
    for (auto ch : s) {
        v = go(v, ch);
        t[v].cnt++;
    }

    ans.assign(k, 0LL);
    dfs(0);

    for (ll i = 0; i < k; i++) {
        cout << ans[i] << nl;
    }
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(t, i);
	}

	return 0;
}
