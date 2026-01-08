#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define ff first
#define ss second
// push, pop: O(1) armotizado e get_min: O(1)
// Útil em problemas de sliding window ou semelhantes
// A ideia é guardar apenas os elementos necessários para encontrar o mínimo
struct MinQueue {
    deque<pi> dq;
    int added = 0, removed = 0;
    // adiciona x no final da fila
    void push(int x) {
        // x > dq.back().ff para MaxQueue
        while (!dq.empty() and x < dq.back().ff) {
            dq.pop_back();
        }
        dq.push_back({x, added});
        added++;
    }
    // remove o elemento do inicio da final
    void pop() { // pop(int x) -> remove x
        // if (!dq.empty() and dq.front().ss == x) {
        if (!dq.empty() and dq.front().ss == removed) {
            dq.pop_front();
        }
        removed++;
    }
    int get_min() {
        return dq.front().ff;
    }
};
// https://noic.com.br/materiais-informatica/curso/data-structures-01/
// https://cp-algorithms.com/data_structures/stack_queue_modification.html