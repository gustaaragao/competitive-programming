#include <bits/stdc++.h>
using namespace std; 

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAXN 100005
ll n, c, t, p[MAXN];

bool is_possible(ll m) {
    int comp = 1;
     // o quanto um competidor consegue comer
    ll resta = t*m;
    for (int i = 0; i < n; i++) {
        if(resta >= p[i]) {
            resta -= p[i];
        } else {
            comp++;
            resta = t*m;
            i--;
        }
        // Preciso de mais competidores
        if (comp > c) return false;
    }
    // É possível comer todas as pipocas no tempo m
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> c >> t;
    for (int i = 0; i < n; i++) cin >> p[i];
    int l = 0, r = 1e9+5;
    while (l < r) {
        int m = (l+r)/2;
        if (!is_possible(m)) l = m+1;
        else r = m;
    }
    cout << l << endl;
}