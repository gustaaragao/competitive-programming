#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define endl '\n' //<< flush
#define dbg(x) cerr << #x << " = " << x << endl
#define pdbg(x) cerr << #x << " = " << x.ff << "," << x.ss << endl

typedef long long ll;
typedef pair<int, int> pt;

int cross(pt v, pt u) {
    return (v.ff * u.ss) - (v.ss * u.ff);
}

signed main() {
    int tc; cin >> tc;
    while (tc--) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        pt a = {x1, y1}, b = {x2, y2}, c = {x3, y3};
        // vetores v e u
        pt v = {b.ff - a.ff, b.ss - a.ss}, u = {c.ff - a.ff, c.ss - a.ss};
        int prod = cross(v, u);
        if (prod == 0) cout << "TOUCH";
        else if (prod > 0) cout << "LEFT";
        else cout << "RIGHT";
        cout << endl;
    }
}
/*
Dados os três pontos A, B e C, considere os vetores v = B - A e u = C - A.
Queremos descobrir se:
- A, B e C são colineares
- Se C está à direita da reta AB
- Se C está à esquerda da reta AB
Podemos descobrir isso a partir da norma do produto vetorial v x u.
Lembre-se que a norma de v x u é dado por det(v.x   v.y) = (v.x * u.y) - (u.x * v.y)
                                              u.x   u.y
Caso o determinante seja:
- = 0, temos que v e u são paralelos, logo A, B e C são colineares
- < 0, temos que a área é negativa (regra da mão), C está à direita.
- > 0, temos que a área é positiva (regra da mão), C está à esquerda.
*/
