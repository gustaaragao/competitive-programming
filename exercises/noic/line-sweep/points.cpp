#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define HORIZONTAL_INICIO 0
#define VERTICAL 1
#define HORIZONTAL_FIM 2

int main(){ _

    int n; cin >> n;
    
    vector<ti> ev;
    int y_horizontal[n];
    pi x_horizontal[n];
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            // Reta Vertical
            ev.emplace_back(x1, VERTICAL, i);
            x_horizontal[i] = {y1, y2};
        } else {
            // Reta Horizontal
            ev.emplace_back(x1, HORIZONTAL_INICIO, i);
            ev.emplace_back(x2, HORIZONTAL_FIM, i);
            y_horizontal[i] = y1;
        }
    }

    sort(all(ev));

    for (auto [x, tipo, id] : ev) {
        
    }

    return 0;
}