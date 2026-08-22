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
// const int MOD = 1e9 + 7; // 998244353;
// const int INF = 0x3f3f3f3f;
// const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// Esse código pode ser alterado para min, max, gcd, or, ...
// é mais flexível que a MinQueue com deque
// Pilha modificada que mantém o mínimo
// modifique o op para a operação que vc quer
int op(int a, int b) { return a | b; }
// int op(int a, int b) { return min(a, b); }
struct AggStack {
    stack<pi> st;
    // adiciona um novo elemento (O(1))
    void push(int x) {
        int cur = st.empty() ? x : op(st.top().ss, x);
        st.push({x, cur});
    }
    // remove o elemento do topo (O(1))
    void pop() { st.pop(); }
    // retorna o valor agregado do op (mínimo, or, ...)
    int agg() { return st.top().ss; };
    // checa se a pilha está vazia
    bool empty() { return st.empty(); }
    // retorna o topo da pilha
    pi top() { return st.top(); }
};
struct AggQueue {
    AggStack in, out;
    // adiciona um elemento na fila (O(1) amortizado)
    void push(int x) { in.push(x); }
    // remove o primeiro elemento (O(1) amortizado)
    void pop() {
        if (out.empty()) {
            while (!in.empty()) {
                auto [x, cur] = in.top();
                in.pop();
                out.push(x);
            }
        }
        out.pop();
    }
    // retorna o valor agregado da fila (O(1))
    int query() {
        if (in.empty()) return out.agg();
        if (out.empty()) return in.agg();
        return op(in.agg(), out.agg());
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
    int ans = 0, cur = 0;

    AggQueue q;

    // primeira janela
    for (int i = 0; i < k; i++) {
        cur |= arr[i];
        q.push(arr[i]);
    }
    ans ^= cur;

    // demais janelas
    for (int i = k; i < n; i++) {
        // adiciona um elemento
        q.push(arr[i]);
        // remove o primeiro elemento
        q.pop();
        // atualiza a respota
        ans ^= q.query();
    }

    cout << ans << endl;
}
