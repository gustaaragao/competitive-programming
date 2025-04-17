#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int t; cin >> t;
    while (t--) {
        string p, s; cin >> p >> s;

        if (s.size() < p.size()) {
            // s cant be smaller than p
            cout << "NO" << endl;
            continue;
        }

        // two pointers
        ll i = 0, j = 0;
        bool is_valid = true;
        while (i < p.size() && j < s.size()) {
            if (p[i] != s[j]) {
                is_valid = false;
                break;
            }

            char c1 = p[i];
            ll count_p = 0;
            while (i < p.size() && p[i] == c1) {
                count_p++;
                i++;
            }

            char c2 = s[j];
            ll count_s = 0;
            while (j < s.size() && s[j] == c2) {
                j++;
                count_s++;
            }

            if (count_s > (2*count_p) || count_s < count_p) {
                is_valid = false;
                break;
            }
        }
        if (i == p.size() && j == s.size() && is_valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }   
    }

    return 0;
}