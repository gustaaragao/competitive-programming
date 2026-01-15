#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// Consiste em uma Árvore Binária Balanceada (std::set + superpoderes)
// Armazena elementos únicos e de forma ordenada
// Operações:
// 1 - Todas de um std::set
// 2 - find_by_order(k): retorna um iterator para o k-ésimo valor (0-INDEXED) (O(log(n)))
// 3 - order_of_key(k): retorna o número de elementos estritamente menores
// que k. (ou seja, o NÚMERO DE INVERSÕES)
template <class T>
using ordered_set = tree<
    T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;
// Você pode fazer um multiset com ordered_set<pair<T, int>>, o segundo elemento 
// é um índice por exemplo.
signed main() {
    ordered_set<int> s;
    // Inserção
    for (int i = 0; i < 10; i++) s.insert(i);
    // Leitura
    for (auto i : s) cout << i << endl;
    int k = 0;
    // Posição do valor k
    cout << *s.find_by_order(k) << endl;
    // Quantos sao menores do que k O(log|s|):
    cout << s.order_of_key(k) << endl;
    // Remoção - Set
    s.erase(5); // apaga o valor 5 (se existir)
    // apaga o elemento pelo iterator
    auto it = s.find(7);
    if (it != s.end()) s.erase(it);
    // remove todos os menores < 5
    auto it_end = s.lower_bound(5);
    while (s.begin() != it_end) {
        s.erase(s.begin());
    }
}
// https://codeforces.com/blog/entry/123624