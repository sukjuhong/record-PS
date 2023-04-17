#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Path {
    int destination;
    int dist;
};

vector<Path> arr[1001];
int dist[1001];
bool visited[1001];
int n, m;

int GetSmallestNode() {
    int min_value = INT32_MAX;
    int min_idx = -1;
    for (int i=1; i<=n; i++) {
        if (!visited[i] && min_value > dist[i]) {
            min_value = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void Solve() {
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int l, r, dist;
        cin >> l >> r >> dist;
        arr[l].push_back({r, dist});
    }

    int start, end;
    cin >> start >> end;
    fill(dist, dist+1001, INT32_MAX);
    
    dist[start] = 0;
    visited[start] = true;

    for (int i=0; i<arr[start].size(); i++) {
        Path p = arr[start][i];
        int cost = dist[start] + p.dist;
        if (cost < dist[p.destination]) dist[p.destination] = cost;
    }

    for (int i=0; i<n-1; i++) {
        int node = GetSmallestNode();
        visited[node] = true;
        for (int i=0; i<arr[node].size(); i++) {
            Path p = arr[node][i];
            int cost = dist[node] + p.dist;
            if (cost < dist[p.destination]) dist[p.destination] = cost;
        }
    }

    cout << dist[end] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
