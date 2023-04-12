#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int dp[1001][1001];

void Solve() {
    int n, m;
    cin >> n >> m;

    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i=2; i<=n; i++) {
        for (int k=0; k<=i; k++) {
            if (k == 0) dp[i][k] = 1;
            else dp[i][k] = (dp[i-1][k-1] + dp[i-1][k]) % 10007;
        }
    }
    cout << dp[n][m] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    Solve();
    return 0;
}
