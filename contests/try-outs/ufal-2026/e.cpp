#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define int long long

typedef long long ll;
typedef pair<int, int> pi;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;

    vector<string> nomes(n);
    for (auto &x : nomes) cin >> x;
    
    vector<int> pontos(n, 0);
    
    vector<int> ids(n, 0);
    iota(ids.begin(), ids.end(), 0);
    
    int q; cin >> q;
    while (q--) {
        string op; cin >> op;
        if (op == "scoreboard") {
            sort(ids.begin(), ids.end(), [&](int a, int b) {
                if (pontos[a] != pontos[b]) return pontos[a] > pontos[b];
                else return a < b;
            });
            int pos = 1;
            if (pontos[ids[0]] != 0) {
                cout << pos << " " << ids[0]+1 << " " << nomes[ids[0]] << " " << pontos[ids[0]] << endl;
            }
            for (int i = 1; i < n; i++) {
                if (pontos[ids[i]] != 0) {
                    if (pontos[ids[i-1]] != pontos[ids[i]]) pos++;
                    cout << pos << " " << ids[i]+1 << " " << nomes[ids[i]] << " " << pontos[ids[i]] << endl;
                }
            }
        } else {
            int id, x; cin >> id >> x;
            string chute; cin >> chute;
            if (chute == s) {
                pontos[id-1] += x;
                cout << "Updated successfully" << endl;
            } else {
                cout << "Wrong password please try again" << endl;
            }
        }
        cout << "---" << endl;
    }
}