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

void solve(vector<int> &arr, int n, int d) {
    int contador_diff_zero = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) contador_diff_zero++;
        if (contador_diff_zero > 2) break;
    }
    if (contador_diff_zero == 0) {
        cout << -1 << endl;
        return;
    }

    if (contador_diff_zero == 1) {
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                j = i;
                break;
            }
        }
        if (arr[j] >= d) {
            while(d--) cout << (j+1) << " ";
            cout << endl;
            return;
        } else {
            cout << -1 << endl;
            return;
        }
    }

    int j = -1, k = -1;
    for (int i = 0; i < n; i++) {
        if (j != -1 && k != -1) break;
        if (arr[i] != 0) {
            if (j == -1) j = i;
            else (k == -1) k = i;
        }
    }
    int dj = arr[j], dk = arr[k];
    while(d--) {
        if (arr[k] != 0) {
            cout << (k + 1) << " ";
            arr[k]--;
            arr[j] = dj;
        } else {
            cout << (j + 1) << " ";
            arr[j]--;
            arr[k] = dk;
        }
    }
    cout << endl;
}

signed main(){ _

    int n, d; cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    solve(arr, n, d);

}