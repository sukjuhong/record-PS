#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

struct Edge {
    int l;
    int r;
    int weight;
};

int n, m;
vector<Edge> edge;
long long dist[501];
const int INF = 987654321;

bool BellmanFord(int start) {
    dist[start] = 0;
    for (int i=0; i<=m; i++) {
        for (int j=0; j<edge.size(); j++) {
            Edge e = edge[j];
            if (dist[e.l] != INF && dist[e.r] > dist[e.l] + e.weight) {
                dist[e.r] = dist[e.l] + e.weight;
                if (i == m) return false;
            }
        }
    }
    return true;
}

void Solve() {
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }

    fill(dist, dist+501, INF);
    bool result = BellmanFord(1);
    if (!result) cout << -1 << "\n";
    else {
        for (int i=2; i<=n; i++) {
            if (dist[i] == INF) cout << -1 << "\n";
            else cout << dist[i] << "\n";
        }
    }
}

int main() {
    Solve();
    return 0;
}
