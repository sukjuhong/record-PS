#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;
const int INF = 987654321;

int n, m;
int dist[101];
int min_sum_chicken_distance = INF;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken_house;
vector<pair<int, int>> temp_chicken_house;

int get_sum_chicken_distance()
{
    fill(dist, dist + 101, INF);

    for (int i = 0; i < house.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i] = min(dist[i], abs(house[i].first - temp_chicken_house[j].first) + abs(house[i].second - temp_chicken_house[j].second));
        }
    }

    int sum = 0;
    for (int i = 0; i < house.size(); i++)
    {
        sum += dist[i];
    }
    return sum;
}

void comb(int idx, int depth)
{
    if (depth == m)
    {
        min_sum_chicken_distance = min(min_sum_chicken_distance, get_sum_chicken_distance());
        return;
    }

    for (int i = idx; i < chicken_house.size(); i++)
    {
        temp_chicken_house.push_back({chicken_house[i].first, chicken_house[i].second});
        comb(i + 1, depth + 1);
        temp_chicken_house.pop_back();
    }
}

void solve()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
                house.push_back({i, j});
            else if (temp == 2)
                chicken_house.push_back({i, j});
        }
    }

    comb(0, 0);

    cout << min_sum_chicken_distance << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}