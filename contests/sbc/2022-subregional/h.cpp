#include <bits/stdc++.h>
#include <cstdint>
#include <vector>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> ii;
typedef long long ll;

struct Vertice {
    unordered_set<int> children;
    int parent;

    Vertice() {
        children.reserve(10000);
    }
};

void fundir(vector<int> &map, vector<Vertice> &vec, int i, int j) {
    map[j] = map[i];
    
    vec[map[j]].children.merge(vec[map[i]].children);

    for(auto &k : vec[map[i]].children) {
        if(map[k] == i) {
            fundir(map, vec, i, map[k]);
        }
    }
}

int main(void) {
    FAST_IO;

    int ver, are;

    cin >> ver >> are;

    vector<Vertice> verts(ver + 1);
    vector<int> vert_map(ver + 1);
    vert_map.reserve(ver + 1);

    for(int i = 1; i <= ver; i++) {
        verts[i].parent = i;
        vert_map[i] = i;
    }

    for(int i = 1; i <= are; i++) {
        int from, to;

        cin >> from >> to;

        if(verts[vert_map[from]].parent == vert_map[to]) {
            fundir(vert_map, verts, to, from);
        }
        else {
           verts[vert_map[from]].children.insert(to);
           verts[vert_map[to]].parent = verts[vert_map[from]].parent;
        }
    }

    vector<uint8_t> sumi(ver + 1, 1);
    sumi[0] = 0;
    vector<uint8_t> font(ver + 1, 1);
    font[0] = 0;

    for(auto &i : vert) {
        
    }

    int n_sumi = 0, n_font = 0;

    for(auto const& v : sumi) {
        n_sumi += v;
    }

    for(auto const& v : font) {
        n_font += v;
    }

    cout << max(n_font, n_sumi) << '\n';
    
}