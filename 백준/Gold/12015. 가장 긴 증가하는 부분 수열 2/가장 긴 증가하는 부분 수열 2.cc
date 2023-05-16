#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int result[1000000];
int arr[1000000];

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i = 1, j = 0;
    result[0] = arr[0];

    while (i < n)
    {
        if (result[j] < arr[i])
        {
            result[j + 1] = arr[i];
            j += 1;
        }
        else
        {
            int *insert_idx = lower_bound(result, result + j, arr[i]);
            *insert_idx = arr[i];
        }
        i++;
    }

    cout << j + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}