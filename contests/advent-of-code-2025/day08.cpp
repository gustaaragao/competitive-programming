#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int

struct dsu {
    vector<int> parent, size;
    dsu(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int i) {
        return parent[i] = (parent[i] == i) ? i : find(parent[i]);
        // return (parent[i] == i) ? i : find(parent[i]);
    }
    void uni(int a, int b) { // a se torna pai de b
        a = find(a), b = find(b);
        if (a != b) {
            // a -> maior árvore
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

vector<string> tokenizer(string s, string del = " ") {
    // Time: O(n) Space: O(1) 
    vector<string> tokens;
    
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        tokens.push_back(s.substr(start, end - start));
    } while (end != -1);

    return tokens;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<tuple<int,int,int>> arr;
    string in;
    while (cin >> in) {
        vector<string> tokens = tokenizer(in, ",");
        arr.emplace_back(
            stoll(tokens[0]),
            stoll(tokens[1]),
            stoll(tokens[2])
        );
    }
    vector<tuple<int, int, int>> edges;
    int n = (int) arr.size();
    for (int i = 0; i < n; i++) {
        auto [x1, y1, z1] = arr[i];
        for (int j = i+1; j < n; j++) {
            auto [x2, y2, z2] = arr[j];
            int dx = x1 - x2, dy = y1 - y2, dz = z1 - z2;
            int dist = dx*dx + dy*dy + dz*dz;
            edges.push_back({dist, i, j});
        }
    }
    sort(edges.begin(), edges.end());
    // Union Find
    dsu d(n); 
    int t = 0;
    // for (auto [dist, i, j] : edges) {
    //     if (d.find(i) != d.find(j)) {
    //         d.uni(i, j);
    //     }
    //     t++;
    //     if (t == 10) break;
    // }
    int last_i = -1, last_j = -1;
    for (auto [dist, i, j] : edges) {
        if (d.find(i) != d.find(j)) {
            d.uni(i, j);
            last_i = i;
            last_j = j;
        }
        if (d.size[d.find(i)] == n) {
            break;
        }
    }
    auto [x1, y1, z1] = arr[last_i];
    auto [x2, y2, z2] = arr[last_j];
    cout << x1 * x2 << endl;
    // vector<int> cnt(n, 0); // cnt[pai] = qtd de elementos do conjunto de pai
    // for (int i = 0; i < n; i++) {
    //     cnt[d.find(i)]++;
    // }
    // sort(cnt.rbegin(), cnt.rend());
    // cout << cnt[0] * cnt[1] * cnt[2] << endl;
}