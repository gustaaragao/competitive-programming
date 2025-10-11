#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pi;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

template <class T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


bool is_prime(ll x) {
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;

	ll limit = sqrt(x);
	for (ll i = 3; i <= limit; i += 2) {
		if (x % i == 0)
			return false;
	}
	return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		if (is_prime(x))
			cout << "Prime" << endl;
		else
			cout << "Not Prime" << endl;
	}
}

