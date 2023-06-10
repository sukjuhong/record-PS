#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[1000][1000];
int result[1000][1000];
bool visited[1000][1000];
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, 1, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;

    queue<pair<pair<int, int>, int>> q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            } else if (arr[i][j] == 0) {
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int t = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
            if (arr[ny][nx] == 1) {
                result[ny][nx] = t+1;
                visited[ny][nx] = true;
                q.push({{ny, nx}, t+1});
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (j != 0) cout << ' ';
            if (visited[i][j]) cout << result[i][j];
            else cout << -1;
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}