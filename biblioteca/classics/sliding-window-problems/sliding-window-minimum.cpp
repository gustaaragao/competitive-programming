#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define int ll
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
const int MOD = 1e9 + 7; // 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct MinQueue {
    deque<pi> dq;
    int added = 0, removed = 0;
    // adiciona x no final da fila
    void push(int x) {
        while (!dq.empty() and x < dq.back().ff) {
            dq.pop_back();
        }
        dq.push_back({x, added});
        added++;
    }
    // remove o elemento do inicio da final
    void pop() {
        if (!dq.empty() and dq.front().ss == removed) {
            dq.pop_front();
        }
        removed++;
    }
    int get_min() {
        return dq.front().ff;
    }
};

int mult(int a, int b, int m) {
    return ((a % m) * (b % m)) % m;
}

int add(int a, int b, int m) {
    return ((a % m) + (b % m)) % m;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    vector<int> arr(n); arr[0] = x;
    for (int i = 1; i < n; i++) {
        arr[i] = add(mult(a, arr[i-1], c), b, c);
    }
    // for (int i = 0; i < n; i++) cout << arr[i] << " ";
    // cout << endl;
    int ans = 0;
    MinQueue mq;
    int mn = LLONG_MAX;
    // primeira janela
    for (int i = 0; i < k; i++) {
        mn = min(mn, arr[i]);
        mq.push(arr[i]);
    }
    ans ^= mn;

    for (int i = k; i < n; i++) {
        // adiciona novo elemento
        mq.push(arr[i]);
        // remove elemento antigo
        mq.pop();

        // atualiza o minimo
        mn = mq.get_min();
        ans ^= mn;
    }

    cout << ans << endl;
}
