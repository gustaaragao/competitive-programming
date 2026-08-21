pair<ll, string> dp[25][2][2][2];
bool vis[25][2][2][2];

void reset() { memset(vis, 0, sizeof(vis)); }

pair<ll, string> rec(string& x, string& y, int idx, int tight_low,
                     int tight_high, int leading_zeros) {
  if (idx == sz(y)) return {leading_zeros ? 0 : 1, ""};
  if (vis[idx][tight_low][tight_high][leading_zeros])
    return dp[idx][tight_low][tight_high][leading_zeros];

  int l_sup = (tight_high == 1) ? y[idx] - '0' : 9;
  int l_inf = (tight_low == 1) ? x[idx] - '0' : 0;

  ll mx_prod = -1;
  string best = "";
  for (int d = l_inf; d <= l_sup; d++) {
    int new_low = (tight_low and d == l_inf);
    int new_high = (tight_high and d == l_sup);
    int new_lz = (leading_zeros and d == 0);

    pair<ll, string> next = rec(x, y, idx + 1, new_low, new_high, new_lz);
    ll prod;
    string num;
    if (new_lz) {
      prod = next.ff;
      num = next.ss;
    } else {
      prod = (ll)d * next.ff;
      num = to_string(d) + next.ss;
    }
    if (prod > mx_prod) {
      mx_prod = prod;
      best = num;
    }
  }
  vis[idx][tight_low][tight_high][leading_zeros] = 1;
  return dp[idx][tight_low][tight_high][leading_zeros] = {mx_prod, best};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string x, y;
  cin >> x >> y;
  string tmp = "";
  for (int i = 0; i < sz(y) - sz(x); i++) tmp += '0';
  x = tmp + x;

  reset();
  pair<ll, string> ans = rec(x, y, 0, 1, 1, 1);
  if (ans.ss == "") ans.ss = "0";

  cout << ans.ss << endl;
  return 0;
}
// https://codeforces.com/gym/100886/problem/G
