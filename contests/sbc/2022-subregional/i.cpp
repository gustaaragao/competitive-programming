#include <bits/stdc++.h>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> ii;

#define endl '\n'

signed main(void) {
    FAST_IO;

    for (int i = 0; i < 8; i++) {
        int x; cin >> x;
        if (x == 9) {
            cout << "F" << endl;
            return 0;
        }
    }
    cout << "S" << endl; 
}