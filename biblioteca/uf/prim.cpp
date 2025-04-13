#include <bits/stdc++.h>
using namespace std; 

typedef pair<int, int> ii;

vector<int> prim(int n, vector<vector<ii>> &adj, int raiz) {
    vector<int> key(n, numeric_limits<int>::max());      
    vector<int> parent(n, -1);                           
    vector<bool> visited(n, false);                      
    priority_queue<ii, vector<ii>, greater<ii>> pq;   
    
    key[raiz] = 0;
    pq.push({0, raiz});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto &[peso, v] : adj[u]) {
            if (!visited[v] && peso < key[v]) {
                key[v] = peso;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    
    return parent;
}
