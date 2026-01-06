#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        dq.push_back(x);
    }
    int turn = 1, score_a = 0, score_b = 0;
    while (!dq.empty()) {
        int mx;
        if (dq.front() > dq.back()) {
            mx = dq.front();
            dq.pop_front();
        } else {
            mx = dq.back();
            dq.pop_back();
        }
        if (turn) score_a += mx;
        else score_b += mx;
        turn = !turn;
    }
    cout << score_a << " " << score_b << endl;
}