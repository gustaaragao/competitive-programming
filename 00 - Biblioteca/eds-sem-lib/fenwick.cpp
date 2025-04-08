#include <bits/stdc++.h>
using namespace std; 

class FenwickTree {
    private:
        vector<int> tree;
        int n;
    public:
        FenwickTree(int n) : n(n) {
            tree.assign(n + 1, 0);
        }
        
        void build(const vector<int> &data) {
            for (int i = 1; i <= n; i++) {
                tree[i] += data[i - 1];
                int j = i + (i & -i);
                if (j <= n) {
                    tree[j] += tree[i];
                }
            }
        }
        
        void update_value(int index, int delta) {
            index++;
            while (index <= n) {
                tree[index] += delta;
                index += (index & -index);
            }
        }
        
        int query_sum(int index) {
            int sum = 0;
            index++;
            while (index > 0) {
                sum += tree[index];
                index -= (index & -index);
            }
            return sum;
        }
        
        int range_query(int l, int r) {
            return query_sum(r) - (l == 0 ? 0 : query_sum(l - 1));
        }
};
