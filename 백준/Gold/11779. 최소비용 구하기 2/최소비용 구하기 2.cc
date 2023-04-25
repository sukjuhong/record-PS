
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Edge {
    int dest;
    int dist;
};

vector<Edge> graph[1001];
vector<int> result;
int dist[1001];
int parent[1001];
const int INF = 987654321;

struct Comp {
    bool operator()(Edge a, Edge b) { return a.dist > b.dist; }
};

void Trace(vector<int> &result, int end) {
    int cur_point = end;
    while (cur_point) {
        result.push_back(cur_point);
        if (parent[cur_point] == cur_point)
            break;
        cur_point = parent[cur_point];
    }
}

void Dijkstra(int start) {
    priority_queue<Edge, vector<Edge>, Comp> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()) {
        int cur_node = pq.top().dest;
        int cur_dist = pq.top().dist;
        pq.pop();

        if (cur_dist > dist[cur_node])
            continue;

        for (int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].dest;
            int next_dist = cur_dist + graph[cur_node][i].dist;
            if (next_dist < dist[next_node]) {
                parent[next_node] = cur_node;
                dist[next_node] = next_dist;
                pq.push({next_node, next_dist});
            }
        }
    }
}

void Solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        graph[l].push_back({r, d});
    }

    int start, end;
    cin >> start >> end;

    fill(dist + 1, dist + n + 1, INF);

    Dijkstra(start);
    Trace(result, end);

    cout << dist[end] << "\n";
    cout << result.size() << "\n";
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
