#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, m, result;
char arr[103][103];
bool visited[102][102];
bool key_visited[102][102];
bool key[26];
bool flag;
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, 1, -1, 0};

void bfs() {
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny > n + 1 || nx < 0 || nx > m + 1) continue;
            if (visited[ny][nx]) continue;
            if (arr[ny][nx] == '*') continue;
            if (arr[ny][nx] >= 'A' && arr[ny][nx] <= 'Z' && !key[arr[ny][nx]-'A']) continue;
            if (arr[ny][nx] >= 'a' && arr[ny][nx] <= 'z' && !key[arr[ny][nx]-'a']) {
                key[arr[ny][nx] - 'a'] = true;
                flag = true;
            }
            if (arr[ny][nx] == '$' && !key_visited[ny][nx]) {
                key_visited[ny][nx] = true;
                result++;
            }
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
}

void solve() {
    cin >> n >> m;

    for (int i=0; i<=n+1; i++) {
        for (int j=0; j<=m+1; j++) {
            if (i == 0 || j == 0 || i == n+1 || j == m+1) {
                arr[i][j] = '.';
                continue;
            }
            cin >> arr[i][j];
        }
    }

    memset(key, 0, sizeof(key));
    memset(key_visited, 0, sizeof(key_visited));

    string keys;
    cin >> keys;
    if (keys != "0") 
        for (int i=0; i<keys.length(); i++) {
            key[keys[i] - 'a'] = true;
        }

    flag = true;
    result = 0;
    while (flag) {
        flag = false;
        bfs();
    }
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();
    return 0;
}