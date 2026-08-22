#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000000];
bool vis[1000000];
void dfs(int v){
    vis[v] = true;

    for(auto u : adj[v]) if(!vis[u])dfs(u);
}
int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m ; i++)
    {
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    vector<int> comp;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i]){
            dfs(i);
            comp.push_back(i);
        }
    }
    cout << comp.size() - 1 << endl;
    int v = comp[0];
    for(int i =1; i < comp.size(); i++){

        cout << v << " " << comp[i] << endl;
    }
    return 0;
}
