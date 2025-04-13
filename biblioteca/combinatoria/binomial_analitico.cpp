#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

#define PRIMO 1000000007 // 10^9 + 7
#define MAX_N 1000000 // 10^6

ll fat[MAX_N + 1];
ll inv[MAX_N + 1];

// Exponenciacao Rapida (Binaria) --> x^n mod m --> O(log n)
ll exp(ll x, ll n, ll m) {
    x %= m; 
    ll res = 1;
    while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
    return res;
}

// Pre-computa o fatorial de 0 até MAX_N --> O(n)
void fatorial(ll p) {
	fat[0] = 1;
	for (int i = 1; i <= MAX_N; i++) { fat[i] = fat[i - 1] * i % p; }
}

// Pre-computa todos os inversos modulares dos fatoriais de 0 até MAX_N --> O(n + log p)
void inverses(ll p) {
	inv[MAX_N] = exp(fat[MAX_N], p - 2, p);
	for (int i = MAX_N; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
}

// C(n, m) % p
ll binomial_analitico(ll n, ll m, ll p) {
    return fat[n] * inv[m] % p * inv[n - m] % p;
}


int main() { _
    int n; cin >> n;
    
    // Inicializa os vetores de memorizacao
    fatorial(PRIMO);
    
    inverses(PRIMO);

    while (n--) {
        int a, b; cin >> a >> b;
        // cout << binomial(a, b) << endl;
		cout << binomial_analitico(a, b, PRIMO) << endl;
    }

    return 0;
}