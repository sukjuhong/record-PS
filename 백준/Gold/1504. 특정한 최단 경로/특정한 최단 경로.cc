#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Edge {
    int dest;
    int weight;
};

struct Comp {
    bool operator()(Edge a, Edge b) {
        return a.weight > b.weight;
    }
};

vector<Edge> edge[801];
int dist[801];
priority_queue<Edge, vector<Edge>, Comp> pq;

void Dijkstra(int start) {
    fill(dist, dist+801, INT32_MAX);

    dist[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        int current_vertex = pq.top().dest;
        int current_weight = pq.top().weight;
        pq.pop();
        
        for (int i=0; i<edge[current_vertex].size(); i++) {
            int next_vertex = edge[current_vertex][i].dest;
            int next_weight = edge[current_vertex][i].weight;
            if (dist[next_vertex] > current_weight + next_weight) {
                dist[next_vertex] = current_weight + next_weight;
                pq.push({next_vertex, dist[next_vertex]});
            }
        }
    }

}

void Solve() {
    int n, e;
    cin >> n >> e;

    for (int i=0; i<e; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        edge[l].push_back({r, w});
        edge[r].push_back({l, w});
    }

    int u, v;
    cin >> u >> v;

    bool check1 = true, check2 = true;
    int result1 = 0, result2 = 0;
    Dijkstra(1);
    if (dist[u] == INT32_MAX) check1 = false;
    if (dist[v] == INT32_MAX) check2 = false;
    result1 += dist[u];
    result2 += dist[v];
    Dijkstra(u);
    if (dist[v] == INT32_MAX) check1 = false;
    if (dist[n] == INT32_MAX) check2 = false;
    result1 += dist[v];
    result2 += dist[n];
    Dijkstra(v);
    if (dist[n] == INT32_MAX) check1 = false;
    if (dist[u] == INT32_MAX) check2 = false;
    result1 += dist[n];
    result2 += dist[u];
    if (check1 && check2) cout << min(result1, result2) << "\n";
    else if (check1) cout << result1 << "\n";
    else if (check2) cout << result2 << "\n";
    else cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    Solve();
    return 0;
}
