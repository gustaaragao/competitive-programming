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
        int n; cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        
        vector<int> ans(2 * n, -1);
        vector<bool> used(2 * n, false);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ans[i + j - 1] = grid[i - 1][j - 1];
                used[grid[i - 1][j - 1] - 1] = true;
            }
        }
        
        for (int i = 0; i < 2 * n; i++) {
            if (ans[i] != -1) cout << ans[i] << " ";
            else {
                for (int j = 0; j < 2 * n; j++) {
                    if (!used[j]) {
                        used[j] = true;
                        cout << j + 1 << " ";
                    }
                }
            }
        }

        cout << endl;
    }

    return 0;
}