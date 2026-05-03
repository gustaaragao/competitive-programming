#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int MAXN = 5e5+5;
struct modint {
    using m = modint;
    int val;
    modint(int v = 0) { val = v % MOD; }
    int pow(int y) {
        m x = val, res = 1;
        while (y) {
            if (y & 1)
                res *= x;
            x *= x;
            y >>= 1;
        }
        return res.val;
    }
    int inv() { return pow(MOD - 2); }
    void operator=(int o) { val = o % MOD; }
    void operator=(m o) { val = o.val % MOD; }
    void operator+=(m o) { *this = *this + o; }
    void operator-=(m o) { *this = *this - o; }
    void operator*=(m o) { *this = *this * o; }
    void operator/=(m o) { *this = *this / o; }
    bool operator==(m o) { return val == o.val; }
    bool operator!=(m o) { return val != o.val; }
    int operator*(m o) { return ((val * o.val) % MOD); }
    int operator/(m o) { return (val * o.inv()) % MOD; }
    int operator+(m o) { return (val + o.val) % MOD; }
    int operator-(m o) { return (val - o.val + MOD) % MOD; }
    friend istream& operator >>(istream& in, m& a) {
		int val; in >> val; a = m(val); return in;
	}
    friend ostream& operator <<(ostream& out, m a) {
		return out << a.val;
	}
};
modint fat[MAXN], inv[MAXN], invfat[MAXN];
void pre() {
    // Calculando Fatorial
    fat[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fat[i] = fat[i-1] * i;
    // Calculando Inverso Fatorial
    inv[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        int val = MOD / i;
        val = (inv[MOD % i] * val) % MOD;
        val = MOD - val;
        inv[i] = val;
    }
    invfat[0] = 1;
    invfat[MAXN - 1] = modint(fat[MAXN - 1]).inv();
    for (int i = MAXN - 2; i >= 1; i--)
        invfat[i] = invfat[i + 1] * (i + 1);
}
// C(n, k) = n! / (k! * (n - k)!)  
modint comb(int n, int k) {
    modint ans = fat[n] * invfat[k];
    ans *= invfat[n - k];
    return ans;
}
// A(n, k) = n! / (n - k)!
modint arr(int n, int k) {
    modint ans = fat[n] * invfat[n - k];
    return ans;
}
signed main() {
    pre();
    modint a = 10, b = 3; // substituia o MOD para 7
    cout << a + b << endl; // 6
    cout << a - b << endl; // 0
    cout << a * b << endl; // 2
    cout << a / b << endl; // 1
    cout << a.pow(5) << endl; // 5
    cout << comb(5, 2) << endl; // 10 
    cout << arr(5, 2) << endl; // 20
}