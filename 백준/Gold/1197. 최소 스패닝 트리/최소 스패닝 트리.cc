#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int l;
  int r;
  int w;
};

bool comp(Edge& l, Edge& r) {
  return l.w < r.w;
}

vector<Edge> edges;
int parents[10001];

int union_find(int x) {
  if (x == parents[x]) return x;
  return parents[x] = union_find(parents[x]);
}

bool union_merge(int l, int r) {
  int pl = union_find(l);
  int pr = union_find(r);
  if (pl != pr) {
    parents[pr] = pl;
    return true;
  }
  return false;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int v, e;
  cin >> v >> e;

  for (int i=1; i<=v; i++) {
    parents[i] = i;
  }

  for (int i=0; i<e; i++) {
    int l, r, w;
    cin >> l >> r >> w;
    edges.push_back({l, r, w});
  }

  sort(edges.begin(), edges.end(), comp);

  int sum_weight = 0;
  int num_edges = 0;
  for (int i=0; i<edges.size(); i++) {
    int l = edges[i].l;
    int r = edges[i].r;

    if (union_merge(l, r)) {
      sum_weight += edges[i].w;
      num_edges++;
    }

    if (num_edges == v-1) {
      break;
    }
  }

  cout << sum_weight << "\n";
  return 0;
}