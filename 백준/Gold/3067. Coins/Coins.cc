#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int coins[21];
int dp[10001];

void solve() {
    memset(dp, 0, 10001 * sizeof(int));

    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> coins[i];
    }

    int target;
    cin >> target;

    dp[0] = 1;
    for (int i=1; i<=n; i++) 
        for (int j=1; j<=target; j++)
            if (coins[i] <= j)
                dp[j] += dp[j - coins[i]];
    
    cout << dp[target] << endl;
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