#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int v[MAXN];
// O((N + Q)*SQRT(N)) -> Offline Range Queries
int block_size; // block_size = teto(sqrt(n))
// TODO: Criar as EDs do problema
int freq[MAXN], cnt_freq[MAXN], freq_mode;
struct Query {
    int l, r, idx;
    bool operator<(Query o) const {
        return make_pair(l / block_size, r) < 
               make_pair(o.l / block_size, o.r);
    }
};
void add(int idx) {
    int x = v[idx];
    cnt_freq[freq[x]]--;
    freq[x]++;
    cnt_freq[freq[x]]++;
    if (freq[x] > freq_mode) {
        freq_mode = freq[x];
    }
}
void remove(int idx) {
    int x = v[idx];
    if (freq[x] == freq_mode and cnt_freq[freq_mode] == 1) {
        freq_mode--;
    }
    cnt_freq[freq[x]]--;
    freq[x]--;
    cnt_freq[freq[x]]++;

}
int get_answer() {
    return freq_mode;
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
        ans[idx] = get_answer();
    }
    return ans;
}
signed main() {
    int n, q; cin >> n, q;
    block_size = sqrt(n);
    vector<Query> qrys(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;
        qrys[i] = {l, r, i};
    }
    vector<int> ans = mo(qrys);
    for (auto x : ans) cout << x << endl;
}
// https://cp-algorithms.com/data_structures/sqrt_decomposition.html
// Mo para encontrar a maior frequência em [l, r]
// Podemos usar esse código para problema de soma, mínimo, máximo, frequência,
// valores que obedecem uma condição, etc...