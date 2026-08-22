#include <iostream>
#include <set>
#include <iterator>

using namespace std;
using ll = long long;

set<int> positions;
multiset<int> distances;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, n;
    cin >> x >> n;

    positions.insert(0);
    positions.insert(x);
    distances.insert(x);

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;

        auto it = positions.insert(p).first;
        int prevValue = *(prev(it));
        int nextValue = *(next(it));

        distances.erase(distances.find(nextValue - prevValue));
        distances.insert(p - prevValue);
        distances.insert(nextValue - p);

        cout << *distances.rbegin() << endl;
    }

    return 0;
}
