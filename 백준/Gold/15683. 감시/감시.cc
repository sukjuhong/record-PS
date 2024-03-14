#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9][9];
int min_count_empty = 64;

// 방향: 위 아래 왼 오
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Cctv {
  int row;
  int col;
  int type;
};

vector<Cctv> cctvs;

int count_empty() {
  int result = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i][j] == 0) result++;
    }
  }
  return result;
}

void print_arr() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void fill_arr(queue<pair<int, int>> q, int v) {
  while (!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    arr[cy][cx] = v;
    q.pop();
  }
}

void dfs(int idx) {
  if (idx == cctvs.size()) { 
    min_count_empty = min(min_count_empty, count_empty());
    return;
  }

  int cy = cctvs[idx].row;
  int cx = cctvs[idx].col;
  queue<pair<int, int>> qs[4];
  for (int i = 0; i < 4; i++) {
    int ny = cy + dy[i];
    int nx = cx + dx[i];

    while (ny > 0 && ny <= n && nx > 0 && nx <= m && arr[ny][nx] != 6) {
      if (arr[ny][nx] == 0) {
        qs[i].push({ny, nx});
      }
      ny += dy[i];
      nx += dx[i];
    }
  }

  if (cctvs[idx].type == 1) {
    for (int i = 0; i < 4; i++) {
      fill_arr(qs[i], -1);
      dfs(idx + 1);
      fill_arr(qs[i], 0);
    }
  } else if (cctvs[idx].type == 2) {
    for (int i = 0; i <= 2; i += 2) {
      fill_arr(qs[i], -1);
      fill_arr(qs[i + 1], -1);
      dfs(idx + 1);
      fill_arr(qs[i], 0);
      fill_arr(qs[i + 1], 0);
    }
  } else if (cctvs[idx].type == 3) {
    for (int i = 0; i < 2; i++) {
      fill_arr(qs[i], -1);
      for (int j = 2; j < 4; j++) {
        fill_arr(qs[j], -1);
        dfs(idx + 1);
        fill_arr(qs[j], 0);
      }
      fill_arr(qs[i], 0);
    }
  } else if (cctvs[idx].type == 4) {
    for (int i = 0; i < 4; i++) {
      fill_arr(qs[i], -1);
      fill_arr(qs[(i+1)%4], -1);
      fill_arr(qs[(i+2)%4], -1);
      dfs(idx+1);
      fill_arr(qs[i], 0);
      fill_arr(qs[(i+1)%4], 0);
      fill_arr(qs[(i+2)%4], 0);
    }
  } else if (cctvs[idx].type == 5) {
    for (int i = 0; i < 4; i++) {
      fill_arr(qs[i], -1);
    }
    dfs(idx + 1);
    for (int i = 0; i < 4; i++) {
      fill_arr(qs[i], 0);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] >= 1 && arr[i][j] <= 5) {
        cctvs.push_back({i, j, arr[i][j]});
      }
    }
  }

  dfs(0);
  cout << min_count_empty << "\n";
  return 0;
}