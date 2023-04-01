#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Edge {
    int vertex;
    int cost;
};

struct Comp {
    bool operator()(Edge a, Edge b) {
        return a.cost > b.cost;
    }
};

vector<Edge> edge[20001];
int dist[20001];

void solve() {
    int v, e;
    cin >> v >> e;

    int startVertex;
    cin >> startVertex;

    for (int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }

    fill(dist, dist+20001, INT32_MAX);

    priority_queue<Edge, vector<Edge>, Comp> pq;
    pq.push({startVertex, 0});
    dist[startVertex] = 0;

    while (!pq.empty()) {
        int currentVertex = pq.top().vertex;
        int currentCost = pq.top().cost;
        pq.pop();

        for (int i=0; i<edge[currentVertex].size(); i++) {
            int nextVertex = edge[currentVertex][i].vertex;
            int nextCost = edge[currentVertex][i].cost;

            if (dist[nextVertex] > currentCost + nextCost) {
                dist[nextVertex] = dist[currentVertex] + nextCost;
                pq.push({nextVertex, dist[nextVertex]});
            }
        }
    }

    for (int i=1; i<=v; i++) {
        if (dist[i] == INT32_MAX) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}