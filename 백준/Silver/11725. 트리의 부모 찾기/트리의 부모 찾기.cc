#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

queue<int> q;
int parent[100001];
bool visited[100001];
vector<int> connection[100001];

void solve() {
    int n;
    cin >> n;
    
    for (int i=0; i<n-1; i++) {
        int l, r;
        cin >> l >> r;
        connection[l].push_back(r);
        connection[r].push_back(l);
    }

    visited[1] = true;
    q.push(1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i=0; i<connection[node].size(); i++) {
            int next_node = connection[node][i];
            if (!visited[next_node]) {
                parent[next_node] = node;
                visited[next_node] = true;
                q.push(next_node); 
            }
        }
    }

    for (int i=2; i<=n; i++) {
        cout << parent[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}