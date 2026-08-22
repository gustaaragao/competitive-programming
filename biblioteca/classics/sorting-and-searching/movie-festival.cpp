#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ff first
#define ss second

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

	int n; cin >> n;
	vector<pair<int, int>> ev(n);
	for (int i = 0; i < n; i++) {
	    cin >> ev[i].ff >> ev[i].ss;
	}
    sort(ev.begin(), ev.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.ss < b.ss; // Comparando com o tempo de encerramento do evento
    });

    int t = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (ev[i].ff >= t) {
            ans++;
            t = ev[i].ss;
        }
    }

    cout << ans << endl;
}
