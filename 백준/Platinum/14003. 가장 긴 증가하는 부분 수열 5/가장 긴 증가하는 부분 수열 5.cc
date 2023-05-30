#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> arr;
stack<pair<int, int>> trace;

void solve() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    vector<int> result { arr[0] };
    trace.push({result.back(), 1});

    for (int i=1; i<n; i++) {
        int cur = arr[i];
        if (cur > result.back()) {
            result.push_back(cur);
            trace.push({cur, result.size()});
            continue;
        }

        int insert_idx = lower_bound(result.begin(), result.end(), cur) - result.begin();
        result[insert_idx] = cur;
        trace.push({cur, insert_idx+1});
    }

    cout << result.size() << '\n';

    int temp_idx = result.size();
    vector<int> lis;
    while (!trace.empty()) {
        pair<int, int> cur = trace.top();
        trace.pop();

        if (temp_idx == cur.second) {
            lis.push_back(cur.first);
            temp_idx--;
        }
    }
    for (int i=lis.size()-1; i>= 0; i--) {
        cout << lis[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}