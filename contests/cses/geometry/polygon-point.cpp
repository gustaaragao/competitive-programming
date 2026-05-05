#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
#define endl '\n' //<< flush
#define dbg(x) cerr << #x << " = " << x << endl
#define pdbg(x) cerr << #x << " = " << x.ff << "," << x.ss << endl
typedef long long ll;

struct pt {
    int x, y;
    pt(int a=0, int b=0) : x(a), y(b) {}
    friend istream &operator>>(istream &in, pt &p) {
		int x, y; in >> p.x >> p.y; return in;
	}
    bool operator < (const pt p) const {
		if (x != p.x) return x < p.x; return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    // multiplicar um escalar ao vetor
	pt operator * (const int c) const { return pt(x*c, y*c); }
    // produto escalar
	int operator * (const pt p) const { return x*(int)p.x + y*(int)p.y; }
    // produto vetorial (norma de u x v)
    int operator ^ (const pt p) const { return x*(int)p.y - y*(int)p.x; }
};

int inpol(vector<pt>& v, pt p) { // O(|v|)
    int qt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (p == v[i]) return 2;
        int j = (i + 1) % v.size();
        if (p.y == v[i].y and p.y == v[j].y) {
			if ((v[i]-p)*(v[j]-p) <= 0) return 2;
		}
        bool baixo = v[i].y < p.y;
		if (baixo == (v[j].y < p.y)) continue;
		auto t = (p-v[i])^(v[j]-v[i]);
		if (!t) return 2;
		if (baixo == (t > 0)) qt += (baixo ? 1 : -1);
    }
    return qt != 0;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pt> pol(n);
    for (auto &x : pol) cin >> x;
    while (m--) {
        pt x; cin >> x;
        int flag = inpol(pol, x);
        if (flag == 2) {
            cout << "BOUNDARY";
        } else if (flag == 1) {
            cout << "INSIDE";
        } else {
            cout << "OUTSIDE";
        }
        cout << endl;
    }
}