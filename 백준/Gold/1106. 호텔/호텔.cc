#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> citys[20];
int dp[1001];

void solve() {
    int c, n;
    cin >> c >> n;

    for (int i=0; i<n; i++) {
        cin >> citys[i].first >> citys[i].second;
    }

    fill(dp, dp+1001, INT32_MAX);

    for (int i=0; i<n; i++)
        for (int j=1; j<=c; j++)
            if (citys[i].second < j)
                dp[j] = min(dp[j], dp[j - citys[i].second] + citys[i].first);
            else
                dp[j] = min(dp[j], citys[i].first);

    cout << dp[c] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}