// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+5;
int a[N];
int tree[N];

void build(int idx,int value){
    while(idx<=N){
        tree[idx]+=value;
        idx += idx & (-idx);
    }
}

int query(int idx){
    int s=0;
    while(idx>0){
        s+=tree[idx];
        idx -= idx&(-idx);
    }
    return s;
}

int query(int a, int b){
    if(a>b) return 0;
    return query(b) - query(a-1);
}


signed main() {
    int n,q;
    cin >> n >> q;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        build(i,a[i]);
    }

    while(q--){
        int op; cin >> op;
        if(op==1){
            int u,value; cin >> u >> value;
            int tmp=value;
            value = value-a[u];
            a[u] = tmp;
            build(u,value);
        }else{
            int a,b; cin >> a >> b;
            cout << query(a,b) << endl;
        }
    }
}
