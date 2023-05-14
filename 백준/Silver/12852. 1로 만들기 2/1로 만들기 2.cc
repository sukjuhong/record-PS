#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int dp[1000001];
int parent[1000001];
const int INF = 987654321;

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= 1000000; i++)
    {
        dp[i] = INF;
        parent[i] = i;
    }

    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            if (dp[i / 3] + 1 < dp[i])
            {
                dp[i] = dp[i / 3] + 1;
                parent[i] = i / 3;
            }
        }
        if (i % 2 == 0)
        {
            if (dp[i / 2] + 1 < dp[i])
            {
                dp[i] = dp[i / 2] + 1;
                parent[i] = i / 2;
            }
        }
        if (dp[i - 1] + 1 < dp[i])
        {
            dp[i] = dp[i - 1] + 1;
            parent[i] = i - 1;
        }
    }

    int cur_num = n;
    cout << dp[n] - 1 << "\n";
    while (true)
    {
        cout << cur_num << " ";
        if (cur_num == 1)
            break;
        cur_num = parent[cur_num];
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