#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define ff first
#define ss second
// Aggreged Queue e Stack
// - Esse código pode ser alterado para min, max, gcd, or, ...
// - É mais flexível que a MinQueue com deque do arquivo MinQueue.cpp
// - Toda fila pode ser implementada como duas pilhas
// modifique o op para a operação que vc quer (op deve ser agregável)
int op(int a, int b) { return a | b; }
// int op(int a, int b) { return min(a, b); }
struct AggStack {
    // no second do pair tem o valor agregado da operação
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
// https://codeforces.com/blog/entry/143351