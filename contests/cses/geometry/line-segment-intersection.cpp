#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
#define endl '\n' //<< flush
#define dbg(x) cerr << #x << " = " << x << endl
#define pdbg(x) cerr << #x << " = " << x.ff << "," << x.ss << endl
typedef long long ll;
/* PRIMITIVAS */
#define int long long
#define sq(x) ((x)*(int)(x))
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
struct line {
    pt p, q;
    line() {}
    line(pt _p, pt _q) : p(_p), q(_q) {}
    friend istream &operator>>(istream &in, line &r) {
        int x, y; in >> r.p >> r.q; return in;
    }
};
/* PONTO e VETOR */
int dist2(pt p, pt q) { return sq(p.x - q.x) + sq(p.y - q.y); }
// aŕea do paralelogramo formado pelos vetores p->q e p->r
// dividir por 2 retorna a área do triângulo formado pelos pontos
int area2(pt p, pt q, pt r) { return (q - p) ^ (r - q); }
// verifica se p, q, r são colineares
bool col(pt p, pt q, pt r) { return area2(p, q, r) == 0; }
// verifica se p -> q -> r é no sentido anti-horário
bool ccw(pt p, pt q, pt r) { return area2(p, q, r) > 0; }
// quadrante de um ponto -> 1, 2, 3, 4
int quad(pt p) { return (p.x<0)^3*(p.y<0); }
// retorna se ang(p) < ang(q) -> Radial Sort (ordena pelos angulos)
bool compare_angle(pt p, pt q) {
	if (quad(p) != quad(q)) return quad(p) < quad(q);
	return ccw(q, pt(0, 0), p);
}
// rotaciona 90 graus o vetor
// vetor resultante é o normal ao original
pt rotate90(pt p) { return pt(-p.y, p.x); }
/* RETA */
// verifica se P pertence ao segmento R
bool in_seg(pt p, line r) {
    pt a = r.p - p, b = r.q - p;
    // (a * b) <= garante que p está entre [r.p, r.q]
    return (a ^ b) == 0 and (a * b) <= 0;
}
// se o seg de r intersecta o seg de s
bool inter_seg(line r, line s) {
	if (in_seg(r.p, s) or in_seg(r.q, s)
		or in_seg(s.p, r) or in_seg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        line r, s;
        cin >> r >> s;
        if (inter_seg(r, s)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}