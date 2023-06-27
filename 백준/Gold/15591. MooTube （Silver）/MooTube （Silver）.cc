#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<pair<int, int>> matrix[5001];

int bfs(int k, int v) {
    queue<pair<int, int>> q;
    vector<bool> visited(5001);

    q.push({v, -1});
    visited[v] = true;
    int cnt = 0;

    while (!q.empty()) {
        int cur_node = q.front().first;
        int cur_usado = q.front().second;
        q.pop();

        for (int i=0; i<matrix[cur_node].size(); i++) {
            int nxt_node = matrix[cur_node][i].first;
            int nxt_usado = matrix[cur_node][i].second;
            if (visited[nxt_node])
                continue;
            if (cur_usado != -1)
                nxt_usado = min(cur_usado, nxt_usado);
            if (k <= nxt_usado) {
                cnt++;
                q.push({nxt_node, nxt_usado});
                visited[nxt_node] = true;
            }
        }
    }

    return cnt;
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i=1; i<=n-1; i++) {
        int l, r, u;
        cin >> l >> r >> u;
        matrix[l].push_back({r, u});
        matrix[r].push_back({l, u});
    }

    for (int i=1; i<=q; i++) {
        int k, v;
        cin >> k >> v;
        cout << bfs(k, v) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}