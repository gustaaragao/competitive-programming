#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

#define int long long

const int MAXN = 1e4 + 10;
int n, g[MAXN], c[MAXN], fat[MAXN];

int fatorial(int n) {
    if (n==0) return fat[0] = 1;
    if (fat[n] != 0) return fat[n];
    return fat[n] = (n*fatorial(n-1));
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> g[i] >> c[i];
    }
    int atual = 0LL;
    for (int i = 0; i < n; i++) {
        atual += g[i];
        atual -= c[i];
    }
}