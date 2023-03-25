#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[21][2];
int dp[101];

void solve() {
    int n;
    cin >> n;

    for (int j=0; j<2; j++)
        for (int i=1; i<=n; i++) 
            cin >> arr[i][j];
        
    for (int i=1; i<=n; i++) {
        for (int j=100; j>=1; j--) {
            if (arr[i][0] < j)
                dp[j] = max(dp[j], dp[j-arr[i][0]] + arr[i][1]);
        }
    }
    cout << dp[100] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}