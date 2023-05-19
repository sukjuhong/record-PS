#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int total_delay[1001];
int delay[1001];
int depth[1001];

void solve()
{
    vector<int> arr[1001];
    memset(depth, 0, sizeof(depth));
    memset(total_delay, 0, sizeof(total_delay));
    memset(delay, 0, sizeof(delay));

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> delay[i];
        total_delay[i] = delay[i];
    }

    for (int i = 1; i <= k; i++)
    {
        int l, r;
        cin >> l >> r;
        arr[l].push_back(r);
        depth[r]++;
    }

    int w;
    cin >> w;

    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] == 0)
            q.push({i, delay[i]});
    }

    while (!q.empty())
    {
        int cur_node = q.front().first;
        int cur_time = q.front().second;
        q.pop();

        for (int i = 0; i < arr[cur_node].size(); i++)
        {
            int nxt_node = arr[cur_node][i];
            int nxt_time = cur_time + delay[arr[cur_node][i]];
            total_delay[nxt_node] = max(total_delay[nxt_node], nxt_time);
            depth[nxt_node]--;
            if (depth[nxt_node] == 0)
                q.push({nxt_node, total_delay[nxt_node]});
        }
    }

    cout << total_delay[w] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();
    return 0;
}