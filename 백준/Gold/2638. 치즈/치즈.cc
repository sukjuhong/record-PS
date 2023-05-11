#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, m;
int arr[100][100];
int outair[100][100];
bool visited[100][100];
int remain_cheeze;
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, 1, -1, 0};

void melt_cheeze()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (outair[i][j] >= 2)
            {
                arr[i][j] = 0;
                remain_cheeze--;
            }
        }
    }
}

void inflow_air()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nxt_row = row + dy[i];
            int nxt_col = col + dx[i];
            if (nxt_row < 0 || nxt_row >= n || nxt_col < 0 || nxt_col >= m || visited[nxt_row][nxt_col])
                continue;

            if (arr[nxt_row][nxt_col] == 1)
                outair[nxt_row][nxt_col]++;
            else
            {
                q.push({nxt_row, nxt_col});
                visited[nxt_row][nxt_col] = true;
            }
        }
    }
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                remain_cheeze++;
        }
    }

    int cur_time = 0;
    while (remain_cheeze)
    {
        memset(outair, 0, sizeof(outair));
        memset(visited, 0, sizeof(visited));

        inflow_air();
        melt_cheeze();
        cur_time++;
    }
    cout << cur_time << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}