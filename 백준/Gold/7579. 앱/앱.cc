#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int active_app[101];
int cost[101];
int dp[10001];

void solve()
{
    int n, m, size = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> active_app[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        size += cost[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = size; j >= cost[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - cost[i]] + active_app[i]);
        }
    }

    for (int i = 1; i <= size; i++)
    {
        if (dp[i] >= m)
        {
            cout << i << "\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}