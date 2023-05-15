#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
int dp[16][1 << 16];
int dist[16][16];
const int START_NODE = 0;
const int START_BIT = 1 << 0;
const int INF = 987654321;

int dfs(int cur_node, int cur_bit)
{
    if (cur_bit == ((1 << n) - 1))
    {
        if (!dist[cur_node][START_NODE])
            return INF;
        return dist[cur_node][START_NODE];
    }

    int &ret = dp[cur_node][cur_bit];
    if (ret != -1)
        return ret;

    ret = INF;
    for (int i = 0; i < n; i++)
    {
        if (!dist[cur_node][i])
            continue;
        if (cur_bit & (1 << i))
            continue;

        ret = min(ret, dist[cur_node][i] + dfs(i, cur_bit | (1 << i)));
    }
    return ret;
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    int result = dfs(START_NODE, START_BIT);
    cout << result << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}