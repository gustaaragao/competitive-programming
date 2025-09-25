#include <bits/stdc++.h>
using namespace std; 

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAXN 1000005

struct node {
    ll ans, left, right;
};
int n, m; string v; node seg[4*MAXN];

node single(char x) {
    if (x == '(') return {0, 1, 0};
    else return {0, 0, 1};
}
node neutral() {
    return {0, 0, 0};
}
node merge(node a, node b) {
    node res;
    ll news = min(a.left, b.right);
    res.ans = a.ans + b.ans + news;
    res.left = a.left + b.left - news;
    res.right = a.right + b.right - news;
    return res;
}
node build(int p=1, int l=0, int r=n-1) { // O(n)
    if (l == r) return seg[p] = single(v[l]);
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}
node qry(int a, int b, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (b < l or a > r) return neutral();
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return merge(qry(a, b, 2*p, l, m), qry(a, b, 2*p+1, m+1, r));
}
node upd(int i, int x, int p=1, int l=0, int r=n-1) { // O(log(n))
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = single(x);
    int m = (l+r)/2;
    return seg[p] = merge(upd(i, x, 2*p, l, m), upd(i, x, 2*p+1, m+1, r));
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> v >> m; n = v.size();
    build();
    while (m--) {
        int a, b; cin >> a >> b;
        a--; b--;
        cout << (qry(a, b).ans * 2) << endl;
    }
}