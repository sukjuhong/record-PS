#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int matrix[501][2];
int dp[501][501];
const int INF = 987654321;

void solve() {
    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> matrix[i][0] >> matrix[i][1];
    }

    for (int i=1; i<=n; i++) { // 구간의 범위 크기
        for (int j=1; i+j<=n; j++) { // 구간 범위의 시작 지점
            dp[j][i+j] = INF;
            for (int k=j; k<=i+j; k++) // 구간 범위를 두 부분으로 나눌 때의 기준점
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]);
        }
    }

    cout << dp[1][n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}