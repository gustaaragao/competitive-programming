/*
 DSU on Tree (Sack)
 Utilizado para responder queries offline em subárvores.
  
 Exemplo de uso clássico: 
 - "Quantas cores distintas existem na subárvore do vértice U?"
 - "Qual é a cor mais frequente na subárvore do vértice U?"
  
 Complexidade de Tempo: O(N log N)
 Complexidade de Espaço: O(N)
*/

ll n;
vector<ll> adj[MAXN];
ll heavy[MAXN], sz[MAXN], cnt[MAXN];

void dfs(ll u, ll p = -1) { // precomputa filhos pesados e tamanho das subarvores
    sz[u] = 1;
    heavy[u] = -1;
    ll mx = 0;
    for (ll v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > mx) heavy[u] = v, mx = sz[v];
    }
}

void add(ll u, ll p, ll val, ll skip) {
    // cnt[cor[u]] += val;
    for (ll v : adj[u]) {
        if (v == p or v == skip) continue;
        add(v, u, val, skip);
    }
}

void dsu(ll u, ll p=-1, bool keep=false) {
    // 1. computa a resposta para os filhos leves e dps descarta
    for (ll v : adj[u]) {
        if (v == p or v == heavy[u]) continue;
        dsu(v, u, false);
    }
    
    // 2. computa a resposta para o filho pesado e mantem
    if (heavy[u] != -1) dsu(heavy[u], u, true);
    
    // 3. desce a subarvore dos leves para guardar a resposta
    add(u, p, 1, heavy[u]);
    
    // nesse instante cnt[i] tem qts vezes a cor i aparece na subarvore de u
    
    if (!keep) add(u, p, -1, -1); // se for descendente de um leve descarta tudo q foi contado na subarvore de u
}