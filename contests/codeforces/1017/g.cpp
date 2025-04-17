#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t; cin >> t;
    while (t--) {
        int q; cin >> q;
        deque<ll> current_dq, reversed_dq;
        ll current_sum = 0, reversed_sum = 0, total = 0;
        int n = 0;
        while (q--) {
            int s; cin >> s;
            if (s == 1) {
                // Cyclic Shift
                ll temp = current_dq.back();
                current_dq.push_front(temp);
                current_dq.pop_back();
                current_sum -= temp * n;
                current_sum += (total - temp) + temp;

                temp = reversed_dq.front();
                reversed_dq.push_back(temp);
                reversed_dq.pop_front();
                reversed_sum += temp * n;
                reversed_sum -= (total - temp) + temp;
            } else if (s == 2) {
                // Reversal operation
                swap(current_dq, reversed_dq);
                swap(current_sum, reversed_sum);
            } else {
                // Add a new element in the end
                ll k; cin >> k;
                n++;
                
                current_dq.push_back(k);
                current_sum += k * n;

                reversed_dq.push_front(k);
                reversed_sum += total;
                reversed_sum += k;
                total += k;
            }

            cout << current_sum << endl;
        }
    }

    return 0;
}