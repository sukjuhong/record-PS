#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int node_time[10001];
int dp[10001];
vector<int> graph[10001];

void solve() {
    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> node_time[i];
        int m;
        cin >> m;
        for (int j=1; j<=m; j++) {
            int pre_node;
            cin >> pre_node;
            graph[i].push_back(pre_node);
        }
    }


    dp[1] = node_time[1];
    int result = 0;
    for (int i=2; i<=n; i++) {
        int max_pre_node_time = 0;
        for (int pre_node: graph[i]) {
            max_pre_node_time = max(max_pre_node_time, dp[pre_node]);
        }
        dp[i] = max_pre_node_time + node_time[i];
        result = max(result, dp[i]);
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}