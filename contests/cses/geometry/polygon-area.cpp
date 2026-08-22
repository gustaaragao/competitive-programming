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
		in >> p.x >> p.y; return in;
	}
    bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
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

int area2(pt p, pt q, pt r) { return (q - p) ^ (r - q); }

int polarea2(vector<pt> v) {
    int ret = 0;
    for (int i = 0; i < (int)v.size(); i++)
        ret += area2(pt(0, 0), v[i], v[(i+1) % v.size()]);
    return abs(ret);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pt> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << polarea2(v) << endl;
}