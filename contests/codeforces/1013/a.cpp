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
        int n; cin >> n;
        vector<int> acc(10, 0);
        bool is_completed = false;
        int numbers_read = 0;
        while (n--) {
            int x; cin >> x; 
            acc[x]++;
            numbers_read++;
            if (acc[0] >= 3 && acc[1] >= 1 && acc[2] >= 2 && acc[3] >= 1 && acc[5] >= 1 && !is_completed) {
                cout << numbers_read << endl;
                is_completed = true;
            }
        }
        if (!is_completed) cout << 0 << endl;
    }

    return 0;
}