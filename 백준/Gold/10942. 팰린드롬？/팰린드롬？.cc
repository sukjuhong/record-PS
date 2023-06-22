#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[2001];
int dp[2001][2001];

bool pelin(int l, int r) {
    int &ret = dp[l][r];

    if (ret != -1)
        return ret;

    if (l == r || l > r)
        return ret = true;
    else if (arr[l] != arr[r])
        return ret = false;
    
    return ret = pelin(l+1, r-1);
}

void solve() {
    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    memset(dp, -1, sizeof(dp));

    for (int i=1; i<=m; i++) {
        int l, r;
        cin >> l >> r;
        cout << pelin(l, r) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}