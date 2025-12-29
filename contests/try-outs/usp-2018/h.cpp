#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

const int MAXN = 3e4 + 5;

vector<int> v;
map<int, int> coord;
int block_size, diff, n, q, freq[MAXN], freq2[MAXN]; // diff -> qtd de números distintos

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

void add(int idx) {
    int x = v[idx];
    
    if (freq[x] > 0) {
        freq2[freq[x]]--;
    } else {
        diff++;
    }
    
    freq[x]++;
    
    freq2[freq[x]]++;
}

void remove(int idx) {
    int x = v[idx];

    freq2[freq[x]]--;
    
    freq[x]--;

    if (freq[x] > 0) {
        freq2[freq[x]]++;
    } else {
        diff--;
    }
}

int get_answer() {
    // Queremos encontrar o maior x tal que
    // (Qtd de temperaturas distintas com frequência >= x) >= x
    // Podemos calcular a frequência das frequência (ou seja, a qtd de temperaturas) com freq2[]

    // Começamos com todos os distintos (freq >= 1)
    int qt = diff, x = 1;
    while (true) {
        // Se a quantidade de números com freq >= x for >= x, 
        // testamos se conseguimos chegar em x + 1
        if (qt >= x) {
            // Para testar o próximo x, removemos quem tem freq EXATAMENTE x
            // O que sobrar são os números com freq >= x + 1
            if (qt - freq2[x] >= x + 1) {
                qt -= freq2[x];
                x++;
            } else {
                return x;
            }
        } else {
            return x - 1;
        }
    }
}

vector<int> mo(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

void coordinate_compression(vector<int> &a) {
    set<int> s;
    for (auto x : a) s.insert(x);

    int index = 0;
    
    for (auto x : s) {
        coord[x] = index;
        index++;
    }

    for (int i = 0; i < a.size(); i++) {
        a[i] = coord[a[i]];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;

    v = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    coordinate_compression(v);

    block_size = sqrt(n);

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;
        queries[i] = {l, r, i};
    }
    
    vector<int> ans = mo(queries);
    for (auto x : ans) {
        cout << x << endl;
    }
}