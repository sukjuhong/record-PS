#include <functional>
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
    int open_day;
};
struct Comp {
    bool operator()(Path a, Path b) {
        return a.open_day > b.open_day;
    }
};

int parent[100001];
priority_queue<Path, vector<Path>, Comp> pq;

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);
    if (px != py) {
        parent[py] = px;
        return true;
    }
    return false;
}

void Solve() {
    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }

    for (int i=1; i<=m; i++) {
        int l, r, open_day;
        cin >> l >> r >> open_day;
        pq.push({l, r, open_day});
    }
    
    vector<int> result;
    while (true) {
        Path p = pq.top();
        pq.pop();

        if (Union(p.l, p.r))
            result.push_back(p.open_day);

        if (result.size() == n-1) break;
    }

    sort(result.begin(), result.end());
    
    int time = 1;
    for (int i=0; i<result.size(); i++) {
        if (result[i] != time) break;
        time++;
    }
    cout << time << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
