#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;

set<int> s;
// 4 bytes * 500001 = 2MB
ll depth[500001];

void Solve() {
    int n;
    cin >> n;

    ll result = 0;
    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;

        s.insert(0);
        depth[0] = -1LL;
        s.insert(n + 1);
        depth[n + 1] = -1LL;

        auto upper_it = s.upper_bound(cur);
        auto lower_it = upper_it;
        lower_it--;
        depth[cur] = max(depth[*lower_it], depth[*upper_it]) + 1LL;
        result += depth[cur];
        cout << result << "\n";
        s.insert(cur);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
}
