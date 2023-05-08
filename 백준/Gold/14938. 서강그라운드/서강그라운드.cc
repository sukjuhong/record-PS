#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int INF = 987654321;
int n, m, r;
int item[101];
vector<pair<int, int>> graph[101];

int dijkstra(int x) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> pq;

    dist[x] = 0;
    pq.push({0, x});
    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].first;
            int next_dist = cur_dist + graph[cur_node][i].second;
            if (next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= m)
            ret += item[i];
    }
    return ret;
}

void solve() {
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }

    for (int i = 0; i < r; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        graph[l].push_back({r, d});
        graph[r].push_back({l, d});
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        int temp = dijkstra(i);
        result = max(temp, result);
    }
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}