#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n, timer=1, tin[MAXN], tout[MAXN], euler[2*MAXN+1];
vector<vector<int>> adj;
// https://courses.edx.org/asset-v1:ITMOx+I2CPx+3T2016+type@asset+block/lecture-04.pdf
void dfs(int v) {
    tin[v] = timer;
    euler[timer++] = v;
    // for (auto u : adj[v]) if (u != p) { // Árvore
    for (auto u : adj[v]) if (tin[u] == -1) {
        dfs(u);
    }
    tout[v] = timer;
    euler[timer++] = v;
}
// Verifica se A é ancestral de B
bool is_ancestor(int a, int b) {
    // A é ancestral de B <-> tin[a] < tout[b] < tout[a]
    return (tin[a] < tout[b]) and (tout[b] < tout[a]);
}
int main() {
    memset(tin, -1, sizeof(tin));
    n = 9;
    adj = {
        {2, 1},          // A
        {0, 5, 6},       // B
        {0, 3, 4},       // C
        {2, 4},          // D
        {2, 3},          // E
        {1, 6},          // F
        {1, 5, 7, 8},    // G
        {6, 8},          // H
        {6, 7}           // J
    };
    dfs(0);
    for (int i = 0; i < n; i++) {
        char c = i+'A';
        cout << c << ": tin = " << tin[i]
             << ", tout = " << tout[i] << endl;
    }
    for (int i = 1; i < timer; i++) {
        char c = euler[i]+'A';
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
