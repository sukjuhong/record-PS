#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[100001];

void solve()
{
    int n, s;
    cin >> n >> s;

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        sum += temp;
        arr[i] = sum;
    }

    int l = 0, r = 1, min_len = INT32_MAX;
    while (l <= n && r <= n)
    {
        if (arr[r] - arr[l] >= s)
        {
            min_len = min(min_len, r - l);
            l++;
        }
        else
        {
            r++;
        }
    }
    if (min_len == INT32_MAX)
        cout << 0 << "\n";
    else
        cout << min_len << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}