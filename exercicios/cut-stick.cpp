#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

const int MAXN = 3e5 + 10;

int n, q, block_size, v[MAXN], freq[MAXN], freq_freq[MAXN], freq_mode;

struct Query {
    int l, r, idx;
    bool operator<(Query o) const {
        return make_pair(l / block_size, r) < 
               make_pair(o.l / block_size, o.r);
    }
};

void add(int idx) {
    int x = v[idx];
    freq_freq[freq[x]]--;
    freq[x]++;
    freq_freq[freq[x]]++;
    if (freq[x] > freq_mode) {
        freq_mode = freq[x];
    }
}
void remove(int idx) {
    int x = v[idx];
    if (freq[x] == freq_mode and freq_freq[freq_mode] == 1) {
        freq_mode--;
    }
    freq_freq[freq[x]]--;
    freq[x]--;
    freq_freq[freq[x]]++;
}
int get_answer(int l, int r) {
    int len = r - l + 1;

    // cout << "freq mode: " << freq_mode << endl;
    // cout << "freq2: " << freq_freq[freq_mode] << endl;
    // freq <= ceil(x / 2) -> 2freq <= ceil(x) -> 2freq <= x
    if (2*freq_mode <= len) { // Não é possível particionar
        return 1;
    } else {
        return 2 * freq_mode - len;
    }
}

vector<int> mo(vector<Query> qrys) {
    vector<int> ans(qrys.size());
    sort(qrys.begin(), qrys.end());
    // TODO: Inicializar as EDs do problema
    int cur_l = 0, cur_r = -1;
    for (auto [l, r, idx] : qrys) {
        while (cur_l > l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > r) {
            remove(cur_r);
            cur_r--;
        }
        ans[idx] = get_answer(l, r);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    block_size = sqrt(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<Query> qrys(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;
        qrys[i] = {l, r, i};
    }
    vector<int> ans = mo(qrys);
    for (auto x : ans) cout << x << endl;
}