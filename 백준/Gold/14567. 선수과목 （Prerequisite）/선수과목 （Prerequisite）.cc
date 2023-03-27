#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct comp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};
int depth[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i=1; i<=m; i++) {
        int l, r;
        cin >> l >> r;
        pq.push({l, r});
    }

    while (!pq.empty()) {
        pair<int, int> node = pq.top();
        pq.pop();
        depth[node.second] = max(depth[node.second],depth[node.first]+1);
    }

    for (int i=1; i<=n; i++) {
        cout << depth[i]+1 << " ";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}