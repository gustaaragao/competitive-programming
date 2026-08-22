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

const int MAXN = 2e5 + 10;

vector<int> a;
int freq_mode = -1;
multiset<int> modes[MAXN];
unordered_map<int, int> freq, freq_freq;

void add(int i) {
    freq_freq[freq[a[i]]]--;
    freq[a[i]]++;
    freq_freq[freq[a[i]]]++;

    modes[freq[a[i]]].insert(a[i]);
    auto it = modes[freq[a[i]]-1].find(a[i]);
    if (it != modes[freq[a[i]]-1].end()) {
        modes[freq[a[i]]-1].erase(it);
    }

    if (freq[a[i]] > freq_mode) {
        freq_mode = freq[a[i]];
    }
}

void remove(int i) {
    if ((freq[a[i]] == freq_mode) and (freq_freq[freq_mode] == 1)) {
        freq_mode--;
    }

    freq_freq[freq[a[i]]]--;
    freq[a[i]]--;
    freq_freq[freq[a[i]]]++;

    modes[freq[a[i]]].insert(a[i]);
    auto it = modes[freq[a[i]]+1].find(a[i]);
    if (it != modes[freq[a[i]]+1].end()) {
        modes[freq[a[i]]+1].erase(it);
    }
}

signed main(){ // O(nlogn)
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k; cin >> n >> k;
    a = vector<int>(n);
    for (int i = 0;i < n; i++) cin >> a[i];

    // primeira janela
    for (int i = 0; i < k; i++) add(i);

    cout << *modes[freq_mode].begin() << " ";

    // demais janelas
    for (int i = k; i < n; i++) {
        // adiciona um elemento
        add(i);

        // remove o primeiro elemento
        remove(i-k);

        cout << *modes[freq_mode].begin() << " ";
    }
    cout << endl;
}
