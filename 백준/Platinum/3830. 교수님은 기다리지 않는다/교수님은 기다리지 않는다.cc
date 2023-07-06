#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef long long ll;

ll dist[100001];
int parent[100001];

int union_find(int x) {
    if (x == parent[x]) return x;
    int cur_parent = union_find(parent[x]);
    dist[x] += dist[parent[x]];
    return parent[x] = cur_parent;
}

void union_merge(int l, int r, int w) {
    int pl = union_find(l);
    int pr = union_find(r);

    if (pl != pr) {
        dist[pr] = dist[l] - dist[r] + w;
        parent[pr] = pl;
    }
}

void solve() {
    int n, m;
    char comm;

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) return;

        for (int i=1; i<=n; i++) {
            dist[i] = 0;
            parent[i] = i;
        }

        for (int i=1; i<=m; i++) {
            cin >> comm;

            if (comm == '!') {
                int l, r, w;
                cin >> l >> r >> w;
                union_merge(l, r, w);
            } else if (comm == '?') {
                int l, r;
                cin >> l >> r; 
                if (union_find(l) != union_find(r))
                    cout << "UNKNOWN" << '\n';
                else
                    cout << dist[r] - dist[l] << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}