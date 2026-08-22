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
// const int MOD = 1e9 + 7; // 998244353;
// const int INF = 0x3f3f3f3f;
// const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ // O(nlogn)
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0;i < n; i++) cin >> a[i];
    map<int, int> freq;
    vector<int> ans; ans.reserve(n-k+1);
    // primeira janela
    for (int i = 0; i < k; i++) {
        freq[a[i]]++;
    }
    ans.pb(sz(freq));

    // demais janelas
    for (int i = k; i < n; i++) {
        // adiciona um elemento
        freq[a[i]]++;

        // remove o primeiro elemento
        freq[a[i-k]]--;

        if (freq[a[i-k]] == 0) {
            freq.erase(a[i-k]);
        }

        // atualiza a respota
        ans.pb(sz(freq));
    }
    for (auto x : ans) cout << x << " ";
    cout << endl;
}
