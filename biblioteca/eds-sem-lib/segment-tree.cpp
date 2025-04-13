#include <bits/stdc++.h>
using namespace std; 

class SegmentTree {
private:
    int n;
    vector<int> tree;
    vector<int> lazy;

    void build_tree(const vector<int> &data, int idx, int left, int right) {
        if (left == right) {
            tree[idx] = data[left];
        } else {
            int mid = (left + right) / 2;
            build_tree(data, 2 * idx + 1, left, mid);
            build_tree(data, 2 * idx + 2, mid + 1, right);
            tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
        }
    }

    void push_down(int idx, int left, int right) {
        if (lazy[idx] != 0) {
            int mid = (left + right) / 2;
            tree[2 * idx + 1] += lazy[idx] * (mid - left + 1);
            tree[2 * idx + 2] += lazy[idx] * (right - mid);
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
            lazy[idx] = 0;
        }
    }

    void update_range(int idx, int left, int right, int ql, int qr, int val) {
        if (ql > right || qr < left)
            return;
        if (ql <= left && right <= qr) {
            tree[idx] += val * (right - left + 1);
            lazy[idx] += val;
            return;
        }
        push_down(idx, left, right);
        int mid = (left + right) / 2;
        update_range(2 * idx + 1, left, mid, ql, qr, val);
        update_range(2 * idx + 2, mid + 1, right, ql, qr, val);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    int query_range(int idx, int left, int right, int ql, int qr) {
        if (ql > right || qr < left)
            return 0;
        if (ql <= left && right <= qr)
            return tree[idx];
        push_down(idx, left, right);
        int mid = (left + right) / 2;
        int left_sum = query_range(2 * idx + 1, left, mid, ql, qr);
        int right_sum = query_range(2 * idx + 2, mid + 1, right, ql, qr);
        return left_sum + right_sum;
    }

public:
    SegmentTree(const vector<int> &data) {
        n = data.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build_tree(data, 0, 0, n - 1);
    }

    void update(int l, int r, int val) {
        update_range(0, 0, n - 1, l, r, val);
    }

    int query(int l, int r) {
        return query_range(0, 0, n - 1, l, r);
    }
};
