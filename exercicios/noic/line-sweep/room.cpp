#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define ENTRADA 0
#define SAIDA 1

int main(){ _

    int n; cin >> n;
    vector<ti> ev;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        ev.emplace_back(a, ENTRADA, i);
        ev.emplace_back(b, SAIDA, i);
    }

    sort(all(ev));
    int acc = 0, ans = 0;
    for (auto [tempo, tipo, id] : ev) {
        if (tipo == ENTRADA) acc++;
        else acc--;
        ans = max(ans, acc);
    }

    cout << ans << endl;

    vector<int> rooms(n);
    queue<int> pq;
    for (int i = 0; i < ans; i++) pq.push(i+1);
    for (auto [tempo, tipo, id] : ev) {
        if (tipo == ENTRADA) {
            int room = pq.front(); pq.pop();
            rooms[id] = room;
        } else {
            pq.push(rooms[id]);
        }
    } 

    for (auto x : rooms) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

// https://cses.fi/problemset/task/1164/