#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int m, n, k;
int map[50][50];
queue<pair<int, int>> q;
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

void Bfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (map[ny][nx] == 1) {
                map[ny][nx] = 0;
                q.push({ny, nx});
            }
        }
    }
}

void Solve() {
    cin >> m >> n >> k;

    for (int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        map[y][x] = 1;
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (map[i][j] == 1) {
                cnt++;
                map[i][j] = 0;
                q.push({i, j});
                Bfs();
            }
        }
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        Solve();
}
