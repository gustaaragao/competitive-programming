#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<vector<int>> grid(n, vector<int>(m));
        
        if (m % k != 0) {
            // m is not multiple of k 
            // -> i can put all the 1, ..., k numbers one or more times in a same row 
            int x = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] = ++x;
                    if (x == k) x = 0;
                }
            }    
        } else {
            queue<int> q; for (int i = 1; i <= k; i++) q.push(i);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] = q.front();
                    q.push(q.front());
                    q.pop();
                }
                q.push(q.front());
                q.pop(); 
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

    }

    return 0;
}