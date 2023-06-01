#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int dp[1001][1001];

void solve() {
    string l, r;
    cin >> l >> r;

    for (int i=0; i<l.length(); i++) {
        for (int j=0; j<r.length(); j++) {
            if (r[j] == l[i]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    cout << dp[l.length()][r.length()] << '\n';

    stack<char> result;
    int y = l.length(), x = r.length();
    while (x > 0 && y > 0) {
        if (dp[y][x] == dp[y-1][x])
            y--;
        else if (dp[y][x] == dp[y][x-1])
            x--;
        else {
            result.push(r[x-1]);
            y--;
            x--;
        }
    }

    while (!result.empty()) {
        cout << result.top();
        result.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}