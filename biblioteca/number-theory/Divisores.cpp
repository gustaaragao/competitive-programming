#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAXN 100005

vector<int> divisores[MAXN]; 
signed main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) { // O(nlog(n))
        for (int j = i; j <= n; j += i) { // j -> múltiplo de i
            divisores[j].pb(i);
        }
    }
}