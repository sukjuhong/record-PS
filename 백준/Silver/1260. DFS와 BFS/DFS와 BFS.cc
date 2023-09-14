#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
#include <algorithm>
using namespace std;

vector<vector<int>> graph(1001);
bool visited[1001];

void bfs(vector<vector<int>> graph, int start_node) {
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();

        cout << cur_node << " ";

        for (int i=0; i<graph[cur_node].size(); i++) {
            int nxt_node = graph[cur_node][i];
            if (!visited[nxt_node]) {
                q.push(nxt_node);
                visited[nxt_node] = true;
            }
        }
    }
    cout << "\n";
}

void dfs(vector<vector<int>> graph, int start_node) {
    visited[start_node] = true;
    cout << start_node << ' ';

    for (int i=0; i<graph[start_node].size(); i++) {
        int nxt_node = graph[start_node][i];
        if (!visited[nxt_node]) {
            dfs(graph, nxt_node);
        }
    }
}

void solve() {
    int n, m ,v;
    cin >> n >> m >> v;

    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        graph[l].push_back(r);
        graph[r].push_back(l);
    }

    for (int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    memset(visited, 0, sizeof(visited));
    dfs(graph, v);
    cout << "\n";
    memset(visited, 0, sizeof(visited));
    bfs(graph, v);

}

int main() {
    solve();
    return 0;
}