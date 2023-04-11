#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int cost[10001];
int parent[10001];
bool visited[10001];

int Find(int x) {
    if (x == parent[x]) return x;
    return x = Find(parent[x]);
}

void Union(int x, int y) {
    int parent_x = Find(x);
    int parent_y = Find(y);
    if (cost[parent_x] > cost[parent_y]) {
        Union(y, x);
        return;
    }
    parent[parent_y] = parent_x;
}

void Solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i=1; i<=n; i++) {
        cin >> cost[i];
        parent[i] = i;
    }

    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        Union(l, r);
    }

    int remain = k;
    for (int i=1; i<=n; i++) {
        parent[i] = Find(i);
        if (!visited[parent[i]]) {
            visited[parent[i]] = true;
            if (remain < cost[parent[i]]) {
                cout << "Oh no" << "\n";
                return;
            }
            remain -= cost[parent[i]];
        }
    }

    cout << k - remain << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    Solve();
    return 0;
}
