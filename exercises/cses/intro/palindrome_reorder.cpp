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

    string s; cin >> s;    
    map<char, int> mp;
    for (auto c : s) mp[c]++;

    // Verifica se existe solucao para a string s
    if (s.length() % 2 == 0) {
        for (const auto& x : mp) {
            if (x.ss % 2 != 0) {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
    } else {
        bool flag = false;
        for (const auto& x : mp) {
            if (x.ss % 2 != 0 && flag) {
                cout << "NO SOLUTION" << endl;
                return 0;
            } else if (x.ss % 2 != 0) {
                flag = true;
            }
        }
    }

    string half, mid;
    for (const auto& x : mp) {
        if (x.ss % 2 == 0) {
            for (int i = 0; i < x.ss / 2; i++) half += x.ff;
        } else {
            for (int i = 0; i < x.ss; i++) mid += x.ff;
        }
    }
    
    cout << half << mid;
    for (int i = half.size() - 1; i >= 0; i--) cout << half[i];
    cout << endl;

    return 0;
}