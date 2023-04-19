#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Path {
    int l;
    int r;
    int dist;
};

struct Comp {
    bool operator()(Path a, Path b) {
        return a.dist > b.dist;
    }
};

struct ReverseComp {
    bool operator()(Path a, Path b) {
        return a.dist < b.dist;
    }
};

priority_queue<Path, vector<Path>, Comp> pq;
priority_queue<Path, vector<Path>, ReverseComp> reverse_pq;
int parent[1001];

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int l, int r) {
    int pl = Find(l);
    int pr = Find(r);
    if (pl != pr) {
        parent[pr] = pl;
        return true;
    }
    return false;
}

void Solve() {
    int n, m;
    cin >> n >> m;

    int num_path = 0;
    int sum_dist = 0;
    int reverse_num_path = 0;
    int reverse_sum_dist = 0;

    int zl, zr, zdist;
    cin >> zl >> zr >> zdist;
    if (zdist == 0) {
        sum_dist++;
        reverse_sum_dist++;
    }

    for (int i=0; i<m; i++) {
        int l, r, dist;
        cin >> l >> r >> dist;
        Path temp{l, r, !dist};
        pq.push(temp);
        reverse_pq.push(temp);
    }   

    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }

    while (!pq.empty()) {
        Path p = pq.top();
        pq.pop();

        if (Union(p.l, p.r)) {
            num_path++;
            sum_dist += p.dist;
        }

        if (num_path == n-1) break;
    }

    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }

    while (!reverse_pq.empty()) {
        Path p = reverse_pq.top();
        reverse_pq.pop();

        if (Union(p.l, p.r)) {
            reverse_num_path++;
            reverse_sum_dist += p.dist;
        }

        if (reverse_num_path == n-1) break;
    }

    cout << reverse_sum_dist*reverse_sum_dist - sum_dist*sum_dist << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
