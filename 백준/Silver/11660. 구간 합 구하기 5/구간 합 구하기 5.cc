#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int sum_arr[1025][1025];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int temp;
            cin >> temp;
            sum_arr[i][j] = temp + sum_arr[i-1][j] + sum_arr[i][j-1] - sum_arr[i-1][j-1];
        }
    }

    for (int i=0; i<m; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << sum_arr[y2][x2] - sum_arr[y2][x1-1] - sum_arr[y1-1][x2] + sum_arr[y1-1][x1-1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}