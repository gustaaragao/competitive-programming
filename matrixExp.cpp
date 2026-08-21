// Problema: quantas maneiras conseguimos formar uma linha usando buses(10 metros) e minibuses(5 metros)
// N = comprimento da linha (sempre multiplo de 5)
// K = numero de diferentes cores para minibuses
// L = numero de diferentes cores para buses
// Recorrencia abaixo
// Cel(1,1) = 0, caso base: 0
// Cel(0,1) = L, minibus
// Cel(1,0) = 1, pois com 5 conseguimos escolher um minibus
// Cel(0,0) = K, bus (precisamos de 2 L)
// A potencia é n/5
// (k, l)
// (1, 0)
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MOD = 1000000;
 
struct M6 {
    ll v;
    M6(ll _v = 0) {
        _v %= MOD;
        if (_v < 0) _v += MOD;
        v = _v;
    }
    M6 operator+(const M6& o) const { return M6(v + o.v); }
    M6 operator*(const M6& o) const { return M6(v * o.v); }
    void operator+=(const M6& o) { v = (v + o.v) % MOD; }
};
 
struct Matrix {
    M6 mat[2][2];
    Matrix() {
        mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = M6(0);
    }
    static Matrix identity() {
        Matrix res;
        res.mat[0][0] = M6(1);
        res.mat[1][1] = M6(1);
        return res;
    }
    Matrix operator*(const Matrix& o) const {
        Matrix res;
        for (int i = 0; i < 2; i++)
            for (int k = 0; k < 2; k++)
                for (int j = 0; j < 2; j++)
                    res.mat[i][j] += mat[i][k] * o.mat[k][j];
        return res;
    }
};
 
Matrix power(Matrix a, ll b) {
    Matrix res = Matrix::identity();
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, k, l;
    cin >> n >> k >> l;
 
    ll n_norm = n / 5;
    
    Matrix T;
    T.mat[0][0] = M6(k);  T.mat[0][1] = M6(l);
    T.mat[1][0] = M6(1);  T.mat[1][1] = M6(0);
 
    T = power(T, n_norm);
 
    ll result = T.mat[0][0].v;
 
    printf("%06lld\n", result);
 
    return 0;
}


// outro template
template<typename T,unsigned int N>
struct Matrix{
	array<array<T,N>,N>dat;
	array<T,N>&operator[](int i){return dat[i];}
	const array<T,N>&operator[](int i)const{return dat[i];}
	Matrix(){for(int i=0;i<N;i++)dat[i].fill(T(0));}
	static Matrix eye(){
		Matrix res;
		for(int i=0;i<N;i++)res[i][i]=1;
		return res;
	}
	Matrix operator+(const Matrix&A)const{
		Matrix res;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)
			res[i][j]=dat[i][j]+A[i][j];
		return res;
	}
	Matrix operator*(const Matrix&A)const{
		Matrix res;
		for(int i=0;i<N;i++)for(int k=0;k<N;k++)for(int j=0;j<N;j++)
			res[i][j]+=dat[i][k]*A[k][j];
		return res;
	}
	Matrix pow(long long n)const{
		Matrix a=*this,res=eye();
		for(;n;a=a*a,n>>=1)if(n&1)res=res*a;
		return res;
	}
};
