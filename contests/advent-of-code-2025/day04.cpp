#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(x) (int) (x).size()

int n, m;
vector<string> grid;

const pair<int, int> dir[8] = {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1},
	{1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

bool valid(int i, int j) {
	return i >= 0 and j >= 0 and i < n and j < m 
			and (grid[i][j] == '@' or grid[i][j] == '$');
}

bool is_possible() {
	bool ok = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '@') {
				int cnt = 0;
				for (auto [di, dj] : dir) {
					int ni = i + di, nj = j + dj;
					if (valid(ni, nj)) {
						cnt++;
					}
				}
				if (cnt < 4) {
					grid[i][j] = '$';
					ok = true;
				}
			}
		}
	}
	return ok;
}

int solve() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '$') {
				grid[i][j] = '.';
				ans++;
			}
		}
	}
	return ans;
}

signed main() {
	string in; 
	while (cin >> in) grid.push_back(in);
	n = sz(grid), m = sz(grid[0]);
	
	int ans = 0;
	while (is_possible()) {
		ans += solve();
	}
	
	cout << ans << endl;
}