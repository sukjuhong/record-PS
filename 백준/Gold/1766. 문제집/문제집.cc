#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int depths[32001];
vector<int> graph[32001];
priority_queue<int, vector<int>, greater<int>> pq;

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i=1; i<=m; i++) {
        int l, r;
        cin >> l >> r;
        graph[l].push_back(r);
        depths[r]++;
    }

    for (int i=1; i<=n; i++) {
        if (!depths[i]) 
            pq.push(i);
    }

    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();
        cout << node << " ";

        for (int connect_node: graph[node]) {
            depths[connect_node]--;
            if (!depths[connect_node])
                pq.push(connect_node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}