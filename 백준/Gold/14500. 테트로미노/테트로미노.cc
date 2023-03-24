#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int tetromino[19][2][4] = {
    {
        {0, 0, 0, 0},
        {0, 1, 2, 3}
    },
    {
        {0, 1, 2, 3},
        {0, 0, 0, 0}
    },
    {
        {0, 0, 1, 1},
        {0, 1, 0, 1}
    },
    {
        {0, 1, 2, 2},
        {0, 0, 0, 1}
    },
    {
        {0, 0, 0, -1},
        {0, 1, 2, 2}
    },
    {
        {0, 0, 1, 2},
        {0, 1, 1, 1}
    },
    {
        {0, 1, 1, 1},
        {0, 0, 1, 2}
    },
    {
        {0, 0, 1, 2},
        {0, 1, 0, 0}
    },
    {
        {0, 0, 0, 1},
        {0, 1, 2, 0}
    },
    {
        {0, 0, -1, -2},
        {0, 1, 1, 1}
    },
    {
        {0, 0, 0, 1},
        {0, 1, 2, 2}
    },
    {
        {0, 1, 1, 2},
        {0, 0, 1, 1}
    },
    {
        {0, 0, 1, 1},
        {0, 1, 1, 2}
    },
    {
        {0, 1, 1, 2},
        {0, 0, -1, -1}
    },
    {
        {0, 0, -1, -1},
        {0, 1, 1, 2}
    },
    {
        {0, 0, 0, 1},
        {0, 1, 2, 1}
    },
    {
        {0, 1, 1, 2},
        {0, 0, 1, 0}
    },
    {
        {0, 0, 0, -1},
        {0, 1, 2, 1}
    },
    {
        {0, 0, -1, 1},
        {0, 1, 1, 1}
    }
};
int arr[500][500];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    int max_sum = INT32_MIN;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<19; k++) {
                bool is_break = false;
                int temp_sum = 0;
                for (int l=0; l<4; l++) {
                    int ny = i + tetromino[k][0][l];
                    int nx = j + tetromino[k][1][l];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                        is_break = true;
                        break;
                    }
                    temp_sum += arr[ny][nx];
                }
                if (is_break) continue;
                max_sum = max(max_sum, temp_sum);
            }
        }
    }
    cout << max_sum << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}