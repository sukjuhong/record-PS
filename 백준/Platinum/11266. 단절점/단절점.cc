#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<int> graph[10001];
int node_num[10001];
int node_min[10001];
int cur_node_num;
stack<pii> s;

bool check_cut_node[10001];
bool is_root[10001];
int child[10001];

void dfs(int v, int p)
{
    node_num[v] = node_min[v] = ++cur_node_num;

    for (int nv : graph[v])
    {
        if (nv == p)
            continue;

        if (node_num[v] > node_num[nv])
            s.push({v, nv});

        if (node_num[nv])
            node_min[v] = min(node_min[v], node_num[nv]);
        else
        {
            child[v]++;
            dfs(nv, v);
            node_min[v] = min(node_min[v], node_min[nv]);
            if (node_min[nv] >= node_num[v])
            {
                check_cut_node[v] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    for (int i = 1; i <= e; i++)
    {
        int src, dst;
        cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }

    for (int i = 1; i <= v; i++)
    {
        if (!node_num[i])
        {
            is_root[i] = true;
            dfs(i, 0);
        }
    }

    vector<int> cut_node;
    for (int i = 1; i <= v; i++)
    {
        if (check_cut_node[i] && (!is_root[i] || child[i] >= 2))
            cut_node.push_back(i);
    }

    sort(cut_node.begin(), cut_node.end());

    cout << cut_node.size() << "\n";
    for (int i : cut_node)
        cout << i << " ";
    return 0;
}