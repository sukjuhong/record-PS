#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> lis;
stack<pair<int, int>> trace;
bool is_lis[500001];

void solve() {
    cin >> n;

    for (int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        arr.push_back({l, r});
    }

    sort(arr.begin(), arr.end());

    lis.push_back(arr[0].second);
    trace.push({lis.back(), 1});

    for (int i=1; i<n; i++) {
        pair<int, int> cur = arr[i];
        if (cur.second > lis.back()) {
            lis.push_back(cur.second);
            trace.push({cur.second, lis.size()});
            continue;
        }
        
        int insert_idx = lower_bound(lis.begin(), lis.end(), cur.second) - lis.begin();
        lis[insert_idx] = cur.second;
        trace.push({cur.second, insert_idx+1});
    }

    cout << n - lis.size() << '\n';

    int trace_idx = lis.size();
    while (!trace.empty()) {
        pair<int, int> cur = trace.top();
        trace.pop();

        if (cur.second == trace_idx) {
            is_lis[cur.first] = true;
            trace_idx--;
        }
    }

    for (int i=0; i<n; i++) {
        if (!is_lis[arr[i].second])
            cout << arr[i].first << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}