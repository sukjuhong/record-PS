#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int dp_max[3];
int dp_min[3];
int arr[3];

void solve()
{
    int n;
    cin >> n;

    int temp_0, temp_2;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        temp_0 = dp_max[0], temp_2 = dp_max[2];
        dp_max[0] = max(dp_max[0], dp_max[1]) + arr[0];
        dp_max[2] = max(dp_max[1], dp_max[2]) + arr[2];
        dp_max[1] = max({temp_0, dp_max[1], temp_2}) + arr[1];

        temp_0 = dp_min[0], temp_2 = dp_min[2];
        dp_min[0] = min(dp_min[0], dp_min[1]) + arr[0];
        dp_min[2] = min(dp_min[1], dp_min[2]) + arr[2];
        dp_min[1] = min({temp_0, dp_min[1], temp_2}) + arr[1];
    }

    cout << max({dp_max[0], dp_max[1], dp_max[2]}) << " " << min({dp_min[0], dp_min[1], dp_min[2]}) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}