#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

vector<int> g[N];
int sz[N];
int tot, done[N], cenpar[N];

// done -> marcar um node que foi escolhido como centroid
// cenpar -> pai de cada vertice na arvore de centroides

void calc_sz(int u, int p) {
  tot ++;
  sz[u] = 1;
  for (auto v : g[u]) {
    if(v == p || done[v]) continue;
    calc_sz(v, u);
    sz[u] += sz[v];
  }
}
int find_cen(int u, int p) {
  for (auto v : g[u]) {
    if(v == p || done[v]) continue;
    else if(sz[v] > tot / 2) return find_cen(v, u);
  }
  return u;
}
void decompose(int u, int pre) {
  tot = 0;
  calc_sz(u, pre);
  int cen = find_cen(u, pre);
  cenpar[cen] = pre;
  done[cen] = 1;
  for(auto v : g[cen]) {
    if(v == pre || done[v]) continue;
    decompose(v, cen);
  }
}
int dep[N];
void dfs(int u, int p = 0) {
  for(auto v : g[u]) {
    if(v == p) continue;
    dep[v] = dep[u] + 1;
    dfs(v, u);
  }
}
