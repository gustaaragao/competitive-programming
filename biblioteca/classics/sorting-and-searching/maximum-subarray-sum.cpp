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
    int n; cin >> n;
  vector<long long> a(n);
  for(auto &x:a) cin >> x;

  long long ans=INT_MIN,sum=INT_MIN;
  for(int i=0;i<n;i++){
    sum = max(a[i], sum+a[i]);
    ans = max(ans, sum);
  }
  cout << ans << endl;

      return 0;
}
