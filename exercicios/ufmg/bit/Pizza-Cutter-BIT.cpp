#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()

#define int long long int

typedef pair<int, int> pi;

#define MAXN 100005

struct fenw {
    int n;
    vector<int> bit;
    fenw() {}
    fenw(int size) {
        n = size;
        bit.assign(size + 1, 0);
    }
    // query do prefixo a[0] + a[1] + ... + a[r]
    int qry(int r) {
        int ans = 0;
        for (int i = r + 1; i > 0; i -= i & -i) // i & -i retorna os bits menos signativos de i 
            ans += bit[i];
        return ans;
    }
    // atualiza o valor a[r] = x
    void upd(int r, int x) {
        for (int i = r + 1; i <= n; i += i & -i) bit[i] += x;
    }
};

void coordinate_compression(vector<int> &a) {
    set<int> s; // Conjunto para armazenar todos os números únicos
    for (auto x : a) s.insert(x);
    int index = 0;
    map<int, int> mp; // Map para armazenar os novos elementos
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        mp[*it] = index;
        index++;
    }
    for (int i = 0; i < a.size(); i++) {
        a[i] = mp[a[i]];
    }
};

int count_intersections(vector<pi> &v) {
    if (v.size() < 2) return 0;
    vector<int> end_coords;
    for (auto [beg, end] : v)
    end_coords.pb(end);
    // Comprimir as coordenadas do end de 10^9 para 10^5
    coordinate_compression(end_coords);
    fenw bit(MAXN);
    int intersections = 0LL;
    for (int i = 0; i < end_coords.size(); i++) {
        int end = end_coords[i];
        // inversões = número total de coordenadas - (coordenadas <= i)
        // inversões = número de coordenadas > i
        intersections += (i - bit.qry(end));
        bit.upd(end, 1);
    }
    return intersections;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x, y, h, v; cin >> x >> y >> h >> v;
    vector<pi> hor(h);
    for (int i = 0; i < h; i++) {
        cin >> hor[i].ff >> hor[i].ss;
    }
    vector<pi> ver(v);
    for (int i = 0; i < v; i++) {
        cin >> ver[i].ff >> ver[i].ss;
    }
    sort(all(hor)), sort(all(ver));
    int ans = 1 + (h+v) + (h*v);
    ans += count_intersections(ver);
    ans += count_intersections(hor);
    cout << ans << endl;
}