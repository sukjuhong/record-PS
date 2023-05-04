#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Path {
    int dest;
    int dist;
};

struct Comp {
    bool operator()(Path a, Path b) { return a.dist > b.dist; }
};

vector<Path> arr[1001];
int dist[1001][1001];
int n, m, x;
const int INF = 987654321;

int dijkstra(int start, int end) {
    if (dist[start][end] != INF)
        return dist[start][end];

    priority_queue<Path, vector<Path>, Comp> pq;

    pq.push({start, 0});
    dist[start][start] = 0;

    while (!pq.empty()) {
        int cur_dest = pq.top().dest;
        int cur_dist = pq.top().dist;
        pq.pop();

        for (int i = 0; i < arr[cur_dest].size(); i++) {
            int next_dest = arr[cur_dest][i].dest;
            int next_dist = cur_dist + arr[cur_dest][i].dist;
            if (next_dist < dist[start][next_dest]) {
                dist[start][next_dest] = next_dist;
                pq.push({next_dest, next_dist});
            }
        }
    }

    return dist[start][end];
}

void solve() {
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        arr[l].push_back({r, d});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }

    int result = INT32_MIN;
    for (int i = 1; i <= n; i++) {
        int temp = dijkstra(i, x) + dijkstra(x, i);
        result = max(result, temp);
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