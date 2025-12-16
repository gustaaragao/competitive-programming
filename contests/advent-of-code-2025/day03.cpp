#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(x) (int) (x).size()

signed main() {
	string in;
	int ans = 0;
	while (cin >> in) {
	    int n = sz(in);
	    vector<int> arr;
	    for (int i = 0; i < n; i++) {
			int x = in[i] - '0';
			arr.push_back(x);
		}

		int fir = -1, pos_fir = -1;
		for (int i = 0; i <= n - 12; i++) {
			if (arr[i] > fir) {
				fir = arr[i];
				pos_fir = i;
			}
		}

		string temp;
		temp.reserve(12);
		temp.push_back(fir + '0');

		for (int i = pos_fir + 1; i < n; i++) {
			int remaining = n - i - 1;

            // enquanto puder melhorar o último dígito
            while (!temp.empty() && arr[i] > (temp.back() - '0') && sz(temp) - 1 + remaining + 1 >= 12) {
                temp.pop_back();
            }

            if (sz(temp) < 12) {
                temp.push_back(char(arr[i] + '0'));
            }
		}
		cout << temp << endl; 
		ans += atoll(temp.c_str()); 
	}
    cout << ans << endl;
}