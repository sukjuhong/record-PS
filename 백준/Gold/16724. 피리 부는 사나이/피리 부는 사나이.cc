#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int result;
char arr[1001][1001];
int parent[1000 * 999 + 1000];

int union_find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = union_find(parent[x]);
}

void union_merge(int l, int r) {
    int pl = union_find(l);
    int pr = union_find(r);
    if (pl != pr) {
        parent[pl] = pr;
    } else
        result++;
}

void Solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            parent[(i - 1) * m + j] = (i - 1) * m + j;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int idx = (i - 1) * m + j;
            if (arr[i][j] == 'D') {
                union_merge(idx + m, idx);
            } else if (arr[i][j] == 'U') {
                union_merge(idx - m, idx);
            } else if (arr[i][j] == 'L') {
                union_merge(idx - 1, idx);
            } else {
                union_merge(idx + 1, idx);
            }
        }
    }
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();
    return 0;
}