#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define int ll
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
const int MOD = 1e9 + 7; // 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int mult(int a, int b, int m) {
    return ((a % m) * (b % m)) % m;
}

int add(int a, int b, int m) {
    return ((a % m) + (b % m)) % m;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    vector<int> arr(n); arr[0] = x;
    for (int i = 1; i < n; i++) {
        arr[i] = add(mult(a, arr[i-1], c), b, c);
    }
    int ans = 0, cur = 0;
    for (int i = 0; i < k; i++) {
        cur ^= arr[i];
    }
    ans ^= cur;
    // é possível fazer cur ^ a[i] para remover a[i] de cur
    // pois x ^ x = 0 e y ^ 0 = y
    for (int i = k; i < n; i++) {
        // adiciona elemento
        cur ^= arr[i];
        // remove elemento
        cur ^= arr[i-k];
        // atualiza a resposta
        ans ^= cur;
    }
    cout << ans << endl;
}
