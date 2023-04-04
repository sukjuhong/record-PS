#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<pair<int, int>> arr[100001];
stack<pair<int, int>> s;
bool visited[100001];

void Solve() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int l;
        cin >> l;
        while (true) {
            int r, w;
            cin >> r;
            if (r == -1) break;
            cin >> w;
            arr[l].push_back({r, w});
        }
    }

    s.push({1, 0});
    visited[1] = true;
    int temp_vertex = 1;
    int temp_cost = 0;
    while (!s.empty()) {
        int vertex = s.top().first;
        int cost = s.top().second;
        s.pop();

        for (int i=0; i<arr[vertex].size(); i++) {
            int next_vertex = arr[vertex][i].first;
            int next_cost = arr[vertex][i].second;
            if (!visited[next_vertex]) {
                if (temp_cost < cost + next_cost) {
                    temp_vertex = next_vertex;
                    temp_cost = cost + next_cost;
                }
                s.push({next_vertex, cost + next_cost});
                visited[next_vertex] = true;
            }
        }
    }

    memset(visited, 0, 100001*sizeof(bool));

    int max_vertex = temp_vertex;
    int max_cost = INT32_MIN;
    s.push({temp_vertex, 0});
    visited[temp_vertex] = true;
    while (!s.empty()) {
        int vertex = s.top().first;
        int cost = s.top().second;
        s.pop();

        for (int i=0; i<arr[vertex].size(); i++) {
            int next_vertex = arr[vertex][i].first;
            int next_cost = arr[vertex][i].second;
            if (!visited[next_vertex]) {
                if (max_cost < cost + next_cost) {
                    max_vertex = next_vertex;
                    max_cost = cost + next_cost;
                }
                s.push({next_vertex, cost + next_cost});
                visited[next_vertex] = true;
            }
        }
    }

    cout << max_cost << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Solve();
    return 0;
}