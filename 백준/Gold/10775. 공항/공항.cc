#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int G, P;
int parent[MAX];

int union_find(int x) {
  if (x == parent[x]) return x;
  return parent[x] = union_find(parent[x]);
}

void union_merge(int x, int y) {
  int px = parent[x];
  int py = parent[y];

  if (px != py) {
    if (px > py) swap(px, py);
    parent[py] = px;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> G >> P;

  for (int i = 1; i <= G; i++) {
    parent[i] = i;
  }

  int sum = 0;
  for (int i = 1; i <= P; i++) {
    int a;
    cin >> a;

    int pa = union_find(a);

    if (pa == 0) break;

    union_merge(pa, pa - 1);

    sum++;
  }

  cout << sum << "\n";
  return 0;
}