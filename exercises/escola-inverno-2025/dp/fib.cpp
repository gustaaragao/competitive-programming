#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define MAXN

bool visited[MAXN];
int f[MAXN];

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (visited[n]) return f[n];

    visited[n] = true;
    f[n] = fib(n - 1) + fib(n - 2);
    return f[n];
}