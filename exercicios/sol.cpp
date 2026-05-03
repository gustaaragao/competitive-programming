#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n) {
        int mx = -1, temp = n;
        while (temp) {
            int d = temp % 10; 
            temp /= 10;
            mx = max(mx, d);
        }
        n -= mx;
        ans++;
    }
    cout << ans << endl;
}