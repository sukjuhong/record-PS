#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, m;
int arr[51][51];
bool visited[51][51];
const int d_row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int d_col[8] = {-1, 1, 0, -1, 1, 0, 1, -1};

struct Pos {
    int row;
    int col;
    int cnt;
};

int bfs(int row, int col) {
    queue<Pos> q;
    memset(visited, false, sizeof(visited));

    q.push({row, col, 0});
    visited[row][col] = true;

    while (!q.empty()) {
        int row = q.front().row;
        int col = q.front().col;
        int cnt = q.front().cnt;
        q.pop();
        
        if (arr[row][col] == 1 && cnt != 0)
            return cnt;

        for (int i=0; i<8; i++) {
            int nxt_row = row + d_row[i];
            int nxt_col = col + d_col[i];
            if (nxt_row <= 0 || nxt_row > n || nxt_col <= 0 || nxt_col > m || visited[nxt_row][nxt_col])
                continue;
            visited[nxt_row][nxt_col] = true;
            q.push({nxt_row, nxt_col, cnt+1});
        }
    }

    return 0;
}

void solve() {
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> arr[i][j];
        }
    }

    int result = INT32_MIN;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (arr[i][j] != 1) {
                int tmp = bfs(i, j);
                result = max(result, tmp);
            }
        }
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}