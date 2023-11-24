#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1001][1001];

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    int dp[n + 1][m + 1] = {0};

    int result = INT32_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 1)
            {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                result = max(result, dp[i][j]);
            }
        }
    }

    printf("%d\n", result * result);

    return 0;
}