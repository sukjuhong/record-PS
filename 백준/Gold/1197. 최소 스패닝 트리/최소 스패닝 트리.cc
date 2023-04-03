#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int parent[10001];

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);
    if (px != py) {
        parent[py] = px;
        return true;
    }
    return false;
}

struct Edge {
    int l;
    int r;
    int weight;
};

struct Comp {
    bool operator()(Edge a, Edge b) {
        return a.weight > b.weight;
    }
};

void Solve() {
    int v, e;
    cin >> v >> e;

    priority_queue<Edge, vector<Edge>, Comp> pq;
    for (int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({a, b, c});
    }

    for (int i=1; i<=v; i++) {
        parent[i] = i;
    }

    int num_edge = 0;
    int sum_weight = 0;
    while (true) {
        Edge edge = pq.top();
        pq.pop();

        if (Union(edge.l, edge.r)) {
            num_edge++;
            sum_weight += edge.weight;
        }

        if (num_edge == v-1) break;
    }

    cout << sum_weight << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Solve();
    return 0;
}