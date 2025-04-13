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

double dist_pontos(const Ponto &p1, const Ponto &p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
};


// Reta
struct Reta {
public:
    T a, b, c; // ax + by + c = 0 -> Eq da reta Normal

    Reta(T _a = 0, T _b = 0, T _c = 0): a(_a), b(_b), c(_c)  {}

    Reta(const Ponto &p, const Ponto &q) {
        // pontos P, Q -> (py – qy)x + (qx – px)y + (pxqy – qxpy) = 0
        T _a = p.y - q.y, _b = q.x - p.x, _c = p.x*q.y - q.x*p.y;
        Reta(_a, _b, _c);
    }

    bool ponto_percente(const Ponto &p) {
        return a * p.x + b * p.y + c < eps;
    }

    friend istream& operator>>(istream& in, Reta &r) {
        return in >> r.a >> r.b >> r.c;
    }

    friend ostream& operator<<(ostream &strm, const Reta &r) {
        return strm << r.a << "x + "<< r.b << "y + " << r.c << " = 0"; // debug
    }
};

bool sao_paralelas(const Reta &r1, const Reta &r2) {
    // a1 / b1  = a2 / b2 --> a1 * b2 = a2 * b1 --> a1 * b2 - (a2 * b1) = 0 
    return fabs(r1.a * r2.b - r2.a * r1.b) < eps;
}

bool sao_iguais(const Reta &r1, const Reta &r2) {
    return sao_paralelas(r1, r2) && (fabs(r1.c - r2.c) < eps);
}

bool intersecao_retas(const Reta &r1, const Reta &r2, Ponto &p) {
    T denominador = r1.a * r2.b - r2.a * r1.b;
    if (fabs(denominador) < eps) return false; // coincidentes ou paralelas
    p.x = (r1.b * r2.c - r2.b * r1.c) / denominador;
    p.y = (r2.a * r1.c - r1.a * r2.c) / denominador;
    return true;
}

double dist_ponto_reta(const Ponto &p, const Reta &r) {
    // |a*x + b*y + c| / sqrt(a² + b²)
    return fabs(r.a * p.x + r.b * p.y + r.c) / hypot(r.a, r.b);
}

// TODO: Implementar outras estruturas que estao no livro https://usaco.guide/CP2.pdf#page=197