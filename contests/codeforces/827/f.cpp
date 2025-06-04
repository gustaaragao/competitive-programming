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

const ll P = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int t; cin >> t;
    while (t--) {
        map<char, int> mp_s, mp_t;
        mp_s['a'] = 1; mp_t['a'] = 1;
        int q; cin >> q;
        while (q--) {
            int op, k; string x;
            cin >> op >> k >> x;
            if (op == 1) {
                while(k--) for (auto c : x) mp_s[c]++;
            } else {
                while(k--) for (auto c : x) mp_t[c]++;
            }

            for (const auto& [key, value] : mp_s) {
                if (mp_t[key] == value) continue;
                else if (mp_t[key] > value) {
                    cout << "YES" << endl;
                    break;
                } else {
                    cout << "NO" << endl;
                    break;
                }
            }
        }
    }    

    return 0;
}