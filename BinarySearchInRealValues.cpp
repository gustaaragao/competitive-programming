// No problema abaixo, tinhamos que encontrar um range de 'o' que tivesse maior razao
// quantidade de os/tamanho do range, ou seja, win_rage = wins/(wins+losses)
// Binary Search in real values
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k; cin >> n >> k;
  string s; cin >> s;
 
  vi pref(n+1);
  for(int i=0;i<n;i++){
    pref[i+1]=pref[i]+(s[i]=='o');
  }

  ld l=0,r=n;
  for(int i=0;i<60;i++){
    ld mid = (l+r)/2;

    vector<ld> psum(n+1);
    for(int i=0;i<n;i++){
        if(s[i]=='o')psum[i+1]=psum[i]+mid;
        else psum[i+1]=psum[i]-1;
    }
    ld mn = LINF;
    int j=0;
    bool ok=0;
    for(int i=0;i<=n;i++){
        for(;j<i and pref[i]-pref[j]>=k;j++){
            mn=min(mn,psum[j]);
        }
        // mid * os - xs >= 0?
        if(psum[i]>=mn)ok=true;
    }
    if(ok)r=mid;
    else l=mid;
  }
  // win_rate = wins/(wins+losses) = 1/(1+losses/wins) = 1/(1+r)
  cout<<1.0/(r+1)<<endl;

  return 0;
}
