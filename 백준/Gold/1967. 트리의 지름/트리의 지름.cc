#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Edge {
    int vertex;
    int cost;
};

vector<Edge> arr[10001];
stack<pair<int, int>> s;
bool visited[10001];

void Solve() {
    int n;
    cin >> n;

    for (int i=1; i<n; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        arr[p].push_back({c, w});
        arr[c].push_back({p, w});
    }

    s.push({1, 0});
    visited[1] = true;
    int temp_node = 1;
    int temp_cost = 0;
    while (!s.empty()) {
        int vertex = s.top().first;
        int cost = s.top().second;
        s.pop();

        if (cost > temp_cost) {
            temp_node = vertex;
            temp_cost = cost;
        }
        
        for (Edge e: arr[vertex]) {
            if (!visited[e.vertex]) {
                int next_vertex = e.vertex;
                int next_cost = e.cost;
                s.push({next_vertex, cost+next_cost});
                visited[next_vertex] = true;
            }
        }
    }

    memset(visited, 0, 10001*sizeof(bool));

    s.push({temp_node, 0});
    visited[temp_node] = true;
    temp_cost = 0;
    while (!s.empty()) {
        int vertex = s.top().first;
        int cost = s.top().second;
        s.pop();

        if (cost > temp_cost) {
            temp_node = vertex;
            temp_cost = cost;
        }
        
        for (Edge e: arr[vertex]) {
            if (!visited[e.vertex]) {
                int next_vertex = e.vertex;
                int next_cost = e.cost;
                s.push({next_vertex, cost+next_cost});
                visited[next_vertex] = true;
            }
        }
    }

    cout << temp_cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Solve();
    return 0;
}