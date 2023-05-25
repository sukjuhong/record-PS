#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Pos
{
    int x;
    int y;
    int z;
    int idx;
};

struct Edge
{
    int l;
    int r;
    int dist;
};

struct Comp
{
    bool operator()(Edge &l, Edge &r)
    {
        return l.dist > r.dist;
    }
};

bool comp_x(Pos &l, Pos &r)
{
    return l.x < r.x;
}

bool comp_y(Pos &l, Pos &r)
{
    return l.y < r.y;
}

bool comp_z(Pos &l, Pos &r)
{
    return l.z < r.z;
}

int get_dist(Pos &l, Pos &r)
{
    return min({abs(l.x - r.x), abs(l.y - r.y), abs(l.z - r.z)});
}


Pos planet[100001];
priority_queue<Edge, vector<Edge>, Comp> pq;
int parent[100001];

int union_find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = union_find(parent[x]);
}

bool union_merge(int l, int r)
{
    int pl = union_find(l);
    int pr = union_find(r);
    if (pl != pr)
    {
        parent[pr] = pl;
        return true;
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> planet[i].x >> planet[i].y >> planet[i].z;
        planet[i].idx = i;
        parent[i] = i;
    }

    sort(planet+1, planet+1+n, comp_x);
    for (int i = 1; i < n; i++)
    {
        pq.push({planet[i].idx, planet[i+1].idx, get_dist(planet[i], planet[i + 1])});
    }
    sort(planet+1, planet+1+n, comp_y);
    for (int i = 1; i < n; i++)
    {
        pq.push({planet[i].idx, planet[i+1].idx, get_dist(planet[i], planet[i + 1])});
    }
    sort(planet+1, planet+1+n, comp_z);
    for (int i = 1; i < n; i++)
    {
        pq.push({planet[i].idx, planet[i+1].idx, get_dist(planet[i], planet[i + 1])});
    }

    int num_edge = 0;
    int total_dist = 0;
    while (!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();

        if (union_merge(e.l, e.r))
        {
            num_edge++;
            total_dist += e.dist;
        }

        if (num_edge == n - 1)
            break;
    }

    cout << total_dist << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}