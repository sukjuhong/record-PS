#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int r, c, t;
int arr[50][50];
int add_arr[50][50];
const int dy[4] = {1, 0, 0, -1};
const int dx[4] = {0, 1, -1, 0};
pair<int, int> cleaner[2];

void cleanAir() {
    for (int idx = 0; idx < 2; idx++) {
        if (idx == 0) {
            for (int i = cleaner[idx].first - 1; i > 0; i--) {
                arr[i][0] = arr[i - 1][0];
            }
            for (int i = 0; i < c - 1; i++) {
                arr[0][i] = arr[0][i + 1];
            }
            for (int i = 1; i <= cleaner[idx].first; i++) {
                arr[i - 1][c - 1] = arr[i][c - 1];
            }
            for (int i = c - 1; i > 1; i--) {
                arr[cleaner[idx].first][i] = arr[cleaner[idx].first][i - 1];
            }
            arr[cleaner[idx].first][1] = 0;
        } else {
            for (int i = cleaner[idx].first + 1; i < r - 1; i++) {
                arr[i][0] = arr[i + 1][0];
            }
            for (int i = 0; i < c - 1; i++) {
                arr[r - 1][i] = arr[r - 1][i + 1];
            }
            for (int i = r - 1; i >= cleaner[idx].first; i--) {
                arr[i][c - 1] = arr[i - 1][c - 1];
            }
            for (int i = c - 1; i > 1; i--) {
                arr[cleaner[idx].first][i] = arr[cleaner[idx].first][i - 1];
            }
            arr[cleaner[idx].first][1] = 0;
        }
    }
}

void solve() {
    cin >> r >> c >> t;

    bool check = false;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                if (!check) {
                    cleaner[0] = {i, j};
                    check = true;
                } else {
                    cleaner[1] = {i, j};
                }
            }
        }
    }

    while (t--) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] > 0) {
                    int cnt = 0;
                    int val = arr[i][j] / 5;
                    for (int k = 0; k < 4; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                            continue;
                        if (arr[ny][nx] == -1)
                            continue;
                        add_arr[ny][nx] += val;
                        cnt++;
                    }
                    add_arr[i][j] -= val * cnt;
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                arr[i][j] += add_arr[i][j];
                add_arr[i][j] = 0;
            }
        }

        cleanAir();
    }

    int sum_dust = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == -1)
                continue;
            sum_dust += arr[i][j];
        }
    }
    cout << sum_dust << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
