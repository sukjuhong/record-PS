#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define endl "\n"

int dp[1001][1001];

void solve() {
    string a, b;
    cin >> a >> b;

    for (int i=1; i<=a.length(); i++) {
        for (int j=1; j<=b.length(); j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[a.length()][b.length()] << endl;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}