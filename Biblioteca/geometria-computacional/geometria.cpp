#include <bits/stdc++.h>
using namespace std; 

#define T double

#define eps 1e-9 // x == 0 <-> x < eps

// Ponto
struct ponto {
    public:
    T x; T y;
    
    ponto(T _x = 0, T _y = 0): x(_x),y(_y) {}
    
    ponto operator+(const ponto &p) { return ponto(x + p.x, y + p.y); }
    ponto operator-(const ponto &p) { return ponto(x - p.x, y - p.y); }
    ponto operator*(double k) { return ponto(k* x, k* y); }
    double norma() { return hypot(x, y); }

    
    friend istream& operator>>(istream& in, ponto &p) {
        return in >> p.x >> p.y;
    }

    friend ostream& operator<<(ostream &strm, const ponto &p) {
        return strm << "(" << p.x << ", " << p.y << ")"; // debug
    }
};

double dist_pontos(const ponto &p1, const ponto &p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
};


// Reta
struct reta {
public:
    T a, b, c; // ax + by + c = 0 -> Eq da reta Normal

    reta(T _a = 0, T _b = 0, T _c = 0): a(_a), b(_b), c(_c)  {}

    reta(const ponto &p, const ponto &q) {
        // pontos P, Q -> (py – qy)x + (qx – px)y + (pxqy – qxpy) = 0
        T _a = p.y - q.y, _b = q.x - p.x, _c = p.x*q.y - q.x*p.y;
        reta(_a, _b, _c);
    }

    bool ponto_percente(const ponto &p) {
        return a * p.x + b * p.y + c < eps;
    }

    friend istream& operator>>(istream& in, reta &r) {
        return in >> r.a >> r.b >> r.c;
    }

    friend ostream& operator<<(ostream &strm, const reta &r) {
        return strm << r.a << "x + "<< r.b << "y + " << r.c << " = 0"; // debug
    }
};

bool sao_paralelas(const reta &r1, const reta &r2) {
    // a1 / b1  = a2 / b2 --> a1 * b2 = a2 * b1 --> a1 * b2 - (a2 * b1) = 0 
    return fabs(r1.a * r2.b - r2.a * r1.b) < eps;
}

bool sao_iguais(const reta &r1, const reta &r2) {
    return sao_paralelas(r1, r2) && (fabs(r1.c - r2.c) < eps);
}

bool intersecao_retas(const reta &r1, const reta &r2, ponto &p) {
    T denominador = r1.a * r2.b - r2.a * r1.b;
    if (fabs(denominador) < eps) return false; // coincidentes ou paralelas
    p.x = (r1.b * r2.c - r2.b * r1.c) / denominador;
    p.y = (r2.a * r1.c - r1.a * r2.c) / denominador;
    return true;
}

double dist_ponto_reta(const ponto &p, const reta &r) {
    // |a*x + b*y + c| / sqrt(a² + b²)
    return fabs(r.a * p.x + r.b * p.y + r.c) / hypot(r.a, r.b);
}

// Circulo
struct circulo {
public:
    T a, b, r;
};


// TODO: Implementar outras estruturas que estao no livro https://usaco.guide/CP2.pdf#page=197