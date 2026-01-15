#include <bits/stdc++.h>
using namespace std;
// importas para o hash_table
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
// o unordered_map é fácil de hackear: 
// as operações ficam O(N), podemos melhorar 
// isso com uma função de hash melhor
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    // posso alterar o int para ll e etc...
    size_t operator()(int x) const {
        static const int FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<int, int> x) const {
        static const uint64_t FIXED_RANDOM = 
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) 
            ^ splitmix64(x.second + FIXED_RANDOM);
    }
};
// criando algumas estruturas "seguras"
template <typename K, typename V>
using umap = unordered_map<K, V, custom_hash>;
// o hash table é mais performático em média
template <typename K, typename V>
using ht = gp_hash_table<K, V, custom_hash>;
// https://codeforces.com/blog/entry/62393