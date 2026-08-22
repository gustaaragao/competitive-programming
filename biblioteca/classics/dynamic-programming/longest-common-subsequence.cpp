#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fll;

const int maxN=1001;
ll A[maxN]={0};
ll B[maxN]={0};
ll dp[maxN][maxN]={0};

int main(){_
  int n,m; cin >> n >> m;

  for(int i=1;i<=n;i++) cin >> A[i];
  for(int i=1;i<=m;i++) cin >> B[i];

  vector<ll> ans;

  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(A[j] == B[i]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  cout << dp[m][n] << endl;


  int i=m,j=n;
  while(i>0 && j>0){
    if(A[j] == B[i]){
      ans.push_back(A[j]);
      i--, j--;
    }else if(dp[i-1][j] > dp[i][j-1]) i--;
    else j--;
  }


  reverse(ans.begin(), ans.end());
  for(auto x : ans) cout << x << " ";
  cout << endl;

  return 0;
}
