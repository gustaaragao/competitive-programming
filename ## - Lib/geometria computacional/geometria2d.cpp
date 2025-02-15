#include <bits/stdc++.h>
using namespace std; 

#define T double

#define eps 1e-9 // x == 0 <-> x < eps

// Ponto
struct Ponto {
    public:
    T x; T y;
    
    Ponto(T _x = 0, T _y = 0): x(_x),y(_y) {}
    
    Ponto operator+(const Ponto &p) { return Ponto(x + p.x, y + p.y); }
    Ponto operator-(const Ponto &p) { return Ponto(x - p.x, y - p.y); }
    Ponto operator*(double k) { return Ponto(k* x, k* y); }
    double norma() { return hypot(x, y); }

    
    friend istream& operator>>(istream& in, Ponto &p) {
        return in >> p.x >> p.y;
    }

    friend ostream& operator<<(ostream &strm, const Ponto &p) {
        return strm << "(" << p.x << ", " << p.y << ")"; // debug
    }
};

double distPontos(const Ponto &p1, const Ponto &p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
};


// Reta
struct Reta {
public:
    T a, b, c; // ax + by + c = 0 -> Eq da Reta Normal

    Reta(T _a = 0, T _b = 0, T _c = 0): a(_a), b(_b), c(_c)  {}

    Reta(const Ponto &p, const Ponto &q) {
        // Pontos P, Q -> (py – qy)x + (qx – px)y + (pxqy – qxpy) = 0
        T _a = p.y - q.y, _b = q.x - p.x, _c = p.x*q.y - q.x*p.y;
        Reta(_a, _b, _c);
    }

    bool pontoPercente(const Ponto &p) {
        return a * p.x + b * p.y + c < eps;
    }

    friend istream& operator>>(istream& in, Reta &r) {
        return in >> r.a >> r.b >> r.c;
    }

    friend ostream& operator<<(ostream &strm, const Reta &r) {
        return strm << r.a << "x + "<< r.b << "y + " << r.c << " = 0"; // debug
    }
};

bool saoParalelas(const Reta &r1, const Reta &r2) {
    // a1 / b1  = a2 / b2 --> a1 * b2 = a2 * b1 --> a1 * b2 - (a2 * b1) = 0 
    return fabs(r1.a * r2.b - r2.a * r1.b) < eps;
}

bool saoIguais(const Reta &r1, const Reta &r2) {
    return saoParalelas(r1, r2) && (fabs(r1.c - r2.c) < eps);
}

bool temIntersecao(const Reta &r1, const Reta &r2) {
    return true;
}

double distPontoReta(const Ponto &p, const Reta &r) {
    // |a*x + b*y + c| / sqrt(a² + b²)
    return fabs(r.a * p.x + r.b * p.y + r.c) / hypot(r.a, r.b);
}

#define endl '\n'
int main() {
    Ponto p = Ponto(5, 1);
    Reta r = Reta(3, -1, 1);

    cout << distPontoReta(p, r) << endl;
}