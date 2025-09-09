#include <bits/stdc++.h>
using namespace std; 

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define int long long int

struct pt {
    int x, y, id;
    pt(int x, int y, int id) : x(x), y(y), id(id) {}
    pt() {}
    pt operator-(pt const &o) const {
        return {x - o.x, y - o.y, -1};
    }
    bool operator<(pt const &o) const {
        if (x == o.x) {
            return y < o.y;
        }
        return x < o.x;
    }
    int operator^(pt const &o) const {
        return (int)x * o.y - (int)y * o.x;
    }
};
int ccw(pt const &a, pt const &b, pt const &x) {
    auto p = (b - a) ^ (x - a);
    return (p > 0) - (p < 0);
}
vector<pt> convex_hull(vector<pt> P, bool include_collinear) {
	// include_collinear: define se vai retornar os pontos colineares às bordas 
	// ou seja, pontos da aresta do polígono
    sort(P.begin(), P.end());
    vector<pt> L, U;
    int pop_threshold = include_collinear ? -1 : 0;
    for (auto p : P) {
        while (L.size() >= 2 && ccw(L.end()[-2], L.end()[-1], p) <= pop_threshold) {
            L.pop_back();
        }
        L.push_back(p);
    }
    reverse(P.begin(), P.end());
    for (auto p : P) {
        while (U.size() >= 2 && ccw(U.end()[-2], U.end()[-1], p) <= pop_threshold) {
            U.pop_back();
        }
        U.push_back(p);
    }
    L.insert(L.end(), U.begin() + 1, U.end() - 1);
    return L;
}
signed main(){
    FAST_IO
    int n; cin >> n;
    vector<pt> arr;
    for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		arr.emplace_back(x, y, i+1);
	}
	vector<pt> ans = convex_hull(arr, true);
	cout << ans.size() << endl;
    for (auto [x, y, id] : ans) {
		cout << x << " " << y << endl;
	}
}