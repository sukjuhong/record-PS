#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, m;
int arr[8][8];
queue<pair<int, int>> q;
int result = INT32_MIN;
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, 1, -1, 0};

void comb(int depth, int arr[8][8], int next) {
    if (depth == 3) {
        int temp_arr[8][8];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                temp_arr[i][j] = arr[i][j];
            }
        }
        queue<pair<int, int>> temp_q = q;
        while (!temp_q.empty()) {
            pair<int, int> node = temp_q.front();
            temp_q.pop();
            
            for (int i=0; i<4; i++) {
                int ny = node.first + dy[i];
                int nx = node.second + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (!temp_arr[ny][nx]) {
                    temp_arr[ny][nx] = 2;
                    temp_q.push({ny, nx});
                }
            }
        }

        int count = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!temp_arr[i][j])
                    count++;
            }
        }
        result = max(result, count);
        return;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i*n+j < next) continue;
            if (!arr[i][j]) {
                arr[i][j] = 1;
                comb(depth+1, arr, i*n+j);
                arr[i][j] = 0;
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) q.push({i, j});
        }
    }

    comb(0, arr, 0);
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}