#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

char arr[600][600];
bool visited[600][600];
const int dy[4] = {0, -1, 1, 0};
const int dx[4] = {1, 0, 0, -1};
int cnt = 0;

void solve() {
    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'I') {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || arr[ny][nx] == 'X' || visited[ny][nx])
                continue;
            if (arr[ny][nx] == 'P')
                cnt++;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    if (cnt == 0)
        cout << "TT" << '\n';
    else
        cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}