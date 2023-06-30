#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Conn {
    int l;
    int r;
    int cost;
};

vector<pair<int, int>> matrix;
vector<Conn> conn;
int parent[2000];

bool comp(Conn a, Conn b) {
    return a.cost < b.cost;
}

int union_find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = union_find(parent[x]);
}

bool union_merge(int l, int r) {
    int pl = union_find(l);
    int pr = union_find(r);
    if (pl != pr) {
        parent[pr] = pl;
        return true;
    }
    return false;
}

int square(int x) {
    return x * x;
}

void solve() {
    int n, c;
    cin >> n >> c;

    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        matrix.push_back({x, y});
        parent[i] = i;
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int tmp_dist = square(matrix[i].first-matrix[j].first) + square(matrix[i].second-matrix[j].second);
            if (tmp_dist < c) continue;
            conn.push_back({i, j, tmp_dist});
        }
    }

    sort(conn.begin(), conn.end(), comp);

    int result = 0;
    int num_edge = 0;
    for (int i=0; i<conn.size(); i++) {
        Conn tmp_conn = conn[i];

        if (num_edge == n-1) break;

        if (!union_merge(tmp_conn.l, tmp_conn.r)) continue;

        result += tmp_conn.cost;
        num_edge++;
    }

    if (num_edge != n-1) cout << -1 << '\n';
    else cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}