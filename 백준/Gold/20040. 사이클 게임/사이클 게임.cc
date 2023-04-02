#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int parent[500001];

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    int parent_x = Find(x);
    int parent_y = Find(y);

    if (parent_x != parent_y) {
        parent[parent_x] = parent_y;
        return false;
    }
    return true;
}

void Solve() {
    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }

    for (int i=1; i<=m; i++) {
        int l, r;
        cin >> l >> r;
        if (Union(l, r)) {
            cout << i << "\n";
            return;
        }
    }
    cout << 0 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Solve();
    return 0;
}