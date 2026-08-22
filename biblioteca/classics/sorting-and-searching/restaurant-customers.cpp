#include <bits/stdc++.h>

using namespace std;

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fll;

int main() {
  _

      int n;
  cin >> n;

  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    ll l, r;
    cin >> l >> r;

    a.push_back({l, 1});
    a.push_back({r, -1});
  }

  // definir um evento, nesse caso, entrar e sair do restaurante
  //
  sort(a.begin(), a.end());

  int ans = 0;
  int persons = 0;
  // for(const pair<int, int> &t : a) ou do jeito abaixo
  for (auto [i, j] : a) {
    persons += j;
    ans = max(ans, persons);
  }

  cout << ans << endl;
  return 0;
}
