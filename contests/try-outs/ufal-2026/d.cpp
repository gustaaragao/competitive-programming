#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define int long long

typedef long long ll;
typedef pair<int, int> pi;

#define LEFT 0
#define RIGHT 1

struct intervalo {
    int l, r, id;
};

map<int, int> coord;

void comp(vector<int> &v) {
    set<int> s; for (auto x : v) s.insert(x);
    int idx = 0;
    for (auto x : s) { 
        coord[x] = idx;
        idx++;
    }
    for (int i = 0; i < (int) v.size(); i++) {
        v[i] = coord[v[i]];
    }
}

struct fenw {
    int n;
    vector<int> bit;
    fenw() {}
    fenw(int sz) {
        n = sz;
        bit.assign(n + 1, 0);
    }
    int qry(int r) {
        int ans = 0;
        for (int i = r+1; i > 0; i -= i & -i)
            ans += bit[i];
        return ans;
    }
    void upd(int r, int x) {
        for (int i = r+1; i <= n; i += i & -i) bit[i] += x;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    
    vector<intervalo> v; v.reserve(n);
    vector<int> vals; vals.reserve(2*n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        vals.pb(l), vals.pb(r);
        v.pb({l, r, i});
    }

    // comprime coordenadas
    comp(vals);
    for (int i = 0; i < n; i++) {
        v[i].l = coord[v[i].l];
        v[i].r = coord[v[i].r];
    }

    // ordena por l crescente
    sort(v.begin(), v.end(), [](const intervalo &a, const intervalo &b) {
        return a.l < b.l;
    });

    vector<int> ans(n);
    fenw bit((int) coord.size() + 10);

    for (int i = n-1; i >= 0; i--) {
        ans[v[i].id] = bit.qry(v[i].r - 1);
        bit.upd(v[i].r, 1);
    }

    for (auto x : ans) cout << x << endl;
}