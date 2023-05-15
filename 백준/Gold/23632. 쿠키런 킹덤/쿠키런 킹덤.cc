#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> built;
vector<int> produce[100001];
vector<int> plan[100001];
bool visited[100001];
int depth[100001];

void solve()
{
    int n, m, t;
    cin >> n >> m >> t;

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        built.push_back(temp);
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int temp;
            cin >> temp;
            produce[i].push_back(temp);
        }
    }

    for (int i = 0; i < n - m; i++)
    {
        int num_building, cnt;
        cin >> num_building >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int resource;
            cin >> resource;
            plan[resource].push_back(num_building);
            depth[num_building]++;
        }
    }

    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] == 0)
            q.push({i, 0});
    }

    while (!q.empty())
    {
        int cur_building = q.front().first;
        int cur_time = q.front().second;
        q.pop();

        for (int i = 0; i < produce[cur_building].size(); i++)
        {
            int resource = produce[cur_building][i];
            if (visited[resource])
                continue;

            visited[resource] = true;
            for (int j = 0; j < plan[resource].size(); j++)
            {
                int nxt_building = plan[resource][j];
                depth[nxt_building]--;
                if (depth[nxt_building] == 0 && cur_time + 1 <= t)
                {
                    q.push({nxt_building, cur_time + 1});
                    built.push_back(nxt_building);
                }
            }
        }
    }

    sort(built.begin(), built.end());
    cout << built.size() << "\n";
    for (int i = 0; i < built.size(); i++)
    {
        cout << built[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}