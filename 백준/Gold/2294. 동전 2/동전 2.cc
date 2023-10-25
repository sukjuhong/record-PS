#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int coin[101];
int cache[101][10001];

int exchange_coin(int n, int k)
{
    if (k < 0)
        return INF;
    else if (k == 0)
        return 0;

    int &ret = cache[n][k];
    if (ret)
    {
        return ret;
    }

    int result = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        int tmp = exchange_coin(n, k - coin[i]);
        result = min(result, tmp);
    }

    return ret = result + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    int result = exchange_coin(n, k);
    if (result >= INF)
        cout << -1 << "\n";
    else
        cout << result << "\n";
    return 0;
}