#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

struct Line {
    pii p1;
    pii p2;
};

int n;
Line line[3001];
int depth[3001];
int parent[3001];

int union_find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = union_find(parent[x]);
}

void union_merge(int l, int r) {
    int pl = union_find(l);
    int pr = union_find(r);
    if (pl == pr)
        return;
    parent[pr] = pl;
    depth[pl] += depth[pr];
    depth[pr] = 0;
}

int get_ccw(pii x, pii y, pii z) {
    int result = x.second * y.first + y.second * z.first + z.second * x.first;
    result -= x.first * y.second + y.first * z.second + z.first * x.second;
    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    else
        return 0;
}

bool is_intersect(Line &l, Line &r) {
    pii l_p1 = l.p1;
    pii l_p2 = l.p2;
    pii r_p1 = r.p1;
    pii r_p2 = r.p2;
    int result_a = get_ccw(l.p1, l.p2, r.p1) * get_ccw(l.p1, l.p2, r.p2);
    int result_b = get_ccw(r.p1, r.p2, l.p1) * get_ccw(r.p1, r.p2, l.p2);
    if (result_a == 0 && result_b == 0) {
        if (l_p1 > l_p2)
            swap(l_p1, l_p2);
        if (r_p1 > r_p2)
            swap(r_p1, r_p2);
        return l_p1 <= r_p2 && l_p2 >= r_p1;
    }
    return result_a <= 0 && result_b <= 0;
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        depth[i] = 1;
        cin >> line[i].p1.second >> line[i].p1.first >> line[i].p2.second >>
            line[i].p2.first;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            Line &line_a = line[i];
            Line &line_b = line[j];
            if (is_intersect(line_a, line_b)) {
                union_merge(i, j);
            }
        }
    }

    int num_group = 0;
    int max_depth = 0;
    for (int i = 1; i <= n; i++) {
        if (depth[i] != 0) {
            num_group++;
            max_depth = max(max_depth, depth[i]);
        }
    }
    cout << num_group << '\n';
    cout << max_depth << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
