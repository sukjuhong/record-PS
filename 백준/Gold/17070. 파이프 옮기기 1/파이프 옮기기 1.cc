#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
bool map[17][17];
int dp[17][17][3];

void Solve() {
    cin >> n;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i=2; i<=n; i++) {
        if (map[1][i]) break;
            dp[1][i][0] = 1;
    }

    for (int i=2; i<=n; i++) {
        for (int j=2; j<=n; j++) {
            if (!(map[i-1][j] | map[i][j] | map[i][j-1])) {
                dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
            }
            if (!map[i][j]) {
                dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][1];
                dp[i][j][2] = dp[i-1][j][2] + dp[i-1][j][1];
            }
        }
    }
    
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
