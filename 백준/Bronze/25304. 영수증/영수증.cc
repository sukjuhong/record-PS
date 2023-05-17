#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

void solve()
{
    int cost;
    cin >> cost;

    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp, prod;
        cin >> temp >> prod;
        sum += temp * prod;
    }

    if (cost == sum)
        cout << "Yes"
             << "\n";
    else
        cout << "No"
             << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}