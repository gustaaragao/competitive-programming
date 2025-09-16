#include <bits/stdc++.h>
using namespace std; 

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
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

void solve(){
    int n; cin >> n;
    vector<deque<ll>> arr(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        arr[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> arr[i][j];
        }
    }
    
    sort(all(arr), [](const deque<ll> &a, const deque<ll> &b) {
        // ">" -> Decrescente e "<" -> Crescente
        return a.size() > b.size();
    });

    deque<ll> ans;
    while (arr.size()) {
        deque<ll> cur = *min_element(all(arr));
        for (auto x : cur) ans.pb(x);
        // Eliminar todos que são <= |cur|
        while (arr.size() && arr.back().size() <= cur.size()) {
            arr.pop_back();
        }
        // Podar os restantes
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < cur.size(); j++) {
                arr[i].pop_front();
            }
        }
    }
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

signed main(){
    FAST_IO
    int tc; cin >> tc;
    while (tc--) solve();
}

/*
# Lexicograficamente Mínimo -> Ordem no dicionário
[1, 5, 4] < [2, 0, 0], pois 1 < 2.

[4, 4, 8] < [4, 5, 1], pois 4 = 4 e 4 < 5.

[7, 2] < [7, 2, 1], pois [7, 2] é prefixo de [7, 2, 1]

- o sort(vector<vector<int>>) já ordena de forma LEXICOGRÁFICA
*/