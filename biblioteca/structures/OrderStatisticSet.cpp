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
// 3 - order_of_key(k): retorna o número de elementos estritamente:
//      - menores, se less<T>
//      - maiores, se greater<T>
// que k. (ou seja, o NÚMERO DE INVERSÕES)
template <class T>
using ord_set = tree<
T,              // Tipo da Chave
null_type,      // Tipo do Valor -> Caso seja definido, a ED vira um std::map
less<T>,        // greater<T> -> Ordem Decrescente
rb_tree_tag,    // Red-black Tree -> Inserção, Remoção e Busca em O(log(n))
tree_order_statistics_node_update
>;
template <class T>
using ord_multiset = tree<
    T,              
    null_type,      
    less_equal<T>,  // greater_equal<T> -> Ordem Decrescente
    rb_tree_tag,    
	tree_order_statistics_node_update
>;
signed main() {
    ord_set<int> s;
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
    // Remoção - Multiset
    ord_multiset<int> ms;
    ms.erase(5); // apaga TODOS os 5!
    auto it = ms.find_by_order(ms.order_of_key(5)); // primeiro "5"
    ms.erase(it);   // remove só um
}
// https://codeforces.com/blog/entry/123624