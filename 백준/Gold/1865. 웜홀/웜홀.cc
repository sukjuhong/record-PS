#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Edge {
    int l;
    int r;
    int weight;
};
int dist[501];
vector<Edge> edge;
const int INF = 987654321;

void Solve() {
    fill(dist, dist+501, INF);
    edge.clear();

    int n, m, w;
    cin >> n >> m >> w;

    for (int i=0; i<m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edge.push_back({s, e, t});
        edge.push_back({e, s, t});
    }

    for (int i=0; i<w; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edge.push_back({s, e, -t});
    }

    for (int i=0; i<=n; i++) {
        for (int j=0; j<edge.size(); j++) {
            Edge e = edge[j];
            if (dist[e.r] > dist[e.l] + e.weight) {
                dist[e.r] = dist[e.l] + e.weight;
                if (i == n) {
                    cout << "YES" << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;

    while (t--)
        Solve();
    return 0;
}
