#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

stack<int> s;

void solve()
{
    int n;
    cin >> n;

    long long result = 0;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        while (!s.empty() && s.top() <= temp)
        {
            s.pop();
        }

        result += s.size();
        s.push(temp);
    }

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