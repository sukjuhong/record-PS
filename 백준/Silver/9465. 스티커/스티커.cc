#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
int arr[2][100001];
int dp[2][100001];

void solve() {
    memset(dp, 0, 2*100001*sizeof(int));

    cin >> n;

    for (int i=0; i<2; i++) {
        for (int j=1; j<=n; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][1] = arr[0][1];
    dp[1][1] = arr[1][1];
    for (int j=2; j<=n; j++) {
        for (int i=0; i<2; i++) {
            dp[i][j] = max(dp[!i][j-1], dp[!i][j-2]) + arr[i][j];
        }
    }
    cout << max(dp[0][n], dp[1][n]) << "\n";
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