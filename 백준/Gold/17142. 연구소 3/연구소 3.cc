#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Pos {
    int y;
    int x;
};

int n, m, target;
int answer = INT32_MAX;
int map[50][50];
int visited[50][50];
vector<Pos> virus;
vector<Pos> cur_virus;
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

void spread_virus() {
    fill(&visited[0][0], &visited[49][50], -1);

    queue<Pos> q;
    
    for (int i=0; i<cur_virus.size(); i++) {
        q.push(cur_virus[i]);
        visited[cur_virus[i].y][cur_virus[i].x] = 0;
    }

    int cnt = 0, taken = 0;
    while (!q.empty()) {
        Pos cur_pos = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = cur_pos.y + dy[i];
            int nx = cur_pos.x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (visited[ny][nx] == -1 && map[ny][nx] != 1) {
                visited[ny][nx] = visited[cur_pos.y][cur_pos.x] + 1;
                q.push({ny, nx});
                if (map[ny][nx] == 0) {
                    cnt++;
                    taken = max(taken, visited[ny][nx]);
                }
            }
        }

    }

    if (cnt == target)
        answer = min(answer, taken);
}

void comb_virus(int depth, int start) {
    if (m == depth) {
        spread_virus();
        return;
    }

    for (int i=start; i<virus.size(); i++) {
        cur_virus.push_back(virus[i]);
        comb_virus(depth+1, i+1);
        cur_virus.pop_back();
    }
}

void solve() {
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virus.push_back({i, j});
            } else if (map[i][j] == 0) target++;
        }
    }

    comb_virus(0, 0);

    if (answer != INT32_MAX)
        cout << answer << '\n';
    else
        cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}