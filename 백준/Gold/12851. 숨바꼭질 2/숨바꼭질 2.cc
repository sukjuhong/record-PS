#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

queue<pair<int, int>> q;
bool visited[200001];

bool is_vaild_idx(int idx)
{
    if (idx < 0 || idx > 200000)
        return false;
    return !visited[idx];
}

void solve()
{
    int n, k;
    cin >> n >> k;

    int min_time = 0;
    int num_min_time_way = 0;
    bool flag = false;

    q.push({n, 0});
    while (!q.empty())
    {
        int idx = q.front().first;
        int time = q.front().second;
        q.pop();

        if (idx == k)
        {
            if (flag && min_time != time)
            {
                continue;
            }
            else if (!flag)
            {
                flag = true;
                min_time = time;
            }
            num_min_time_way++;
        }

        visited[idx] = true;
        visited[k] = false;

        if (is_vaild_idx(idx * 2))
        {
            q.push({idx * 2, time + 1});
        }
        if (is_vaild_idx(idx + 1))
        {
            q.push({idx + 1, time + 1});
        }
        if (is_vaild_idx(idx - 1))
        {
            q.push({idx - 1, time + 1});
        }
    }

    cout << min_time << "\n";
    cout << num_min_time_way << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}