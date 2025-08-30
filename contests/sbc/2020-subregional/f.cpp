#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

signed main(){ _

    char turno = 'L';
    int gl = 0, gr = 0, pl = 0, pr = 0;

    string s; cin >> s;
    for (auto c : s) {
        if (c == 'S') {
            if (turno == 'L') {
                pl++;
                if ((pl >= 5 && pl - pr >= 2) || pl == 10) {
                    gl++;
                    pl = 0; 
                    pr = 0;
                }
            } else  {
                pr++;
                if ((pr >= 5 && pr - pl >= 2) || pr == 10) {
                    gr++;
                    pr = 0; 
                    pl = 0;
                }
            }
            
        } else if (c == 'R') {
            if (turno == 'L') {
                pr++;
                if ((pr >= 5 && pr - pl >= 2) || pr == 10) {
                    gr++;
                    pr = 0; 
                    pl = 0;
                }
                turno = 'R';
            } else  {
                pl++;
                if ((pl >= 5 && pl - pr >= 2) || pl == 10) {
                    gl++;
                    pl = 0; 
                    pr = 0;
                }
                turno = 'L';
            }
        } else { // c == 'Q'
            if (gl == 2) {
                cout << "2 (winner) - " << gr << endl;
            } else if (gr == 2) {
                cout << gl << " - 2 (winner)" << endl;
            } else {
                if (turno == 'L') {
                    cout << gl << " (" << pl << "*)" << " - " << gr << " (" << pr << ")" << endl;
                } else { // turno == 'R'
                    cout << gl << " (" << pl << ")" << " - " << gr << " (" << pr << "*)" << endl;
                }
            }
        }
    }
}