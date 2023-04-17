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

int problem = 1;
int n;
int map[125][125];
int dist[125][125];
bool visited[125][125];
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, 1, -1, 0};

Pos GetSmallestPos() {
    Pos min_pos = {-1, -1};
    int min_value = INT32_MAX;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!visited[i][j] && dist[i][j] < min_value) {
                min_pos.y = i, min_pos.x = j;
                min_value = dist[i][j];
            }
        }
    }
    return min_pos;
}

void Solve() {
    while (true) {
        fill(&dist[0][0], &dist[124][125], INT32_MAX);
        fill(&visited[0][0], &visited[124][125], false);

        cin >> n;

        if (n == 0) return;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> map[i][j];
            }
        }

        dist[0][0] = map[0][0];
        visited[0][0] = true;
        dist[0][1] = dist[0][0] + map[0][1];
        dist[1][0] = dist[0][0] + map[1][0];
        
        for (int i=0; i<n*n-1; i++) {
            Pos p = GetSmallestPos();
            visited[p.y][p.x] = true;
            for (int j=0; j<4; j++) {
                int ny = p.y + dy[j];
                int nx = p.x + dx[j];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
                int cost = dist[p.y][p.x] + map[ny][nx];
                if (dist[ny][nx] > cost) dist[ny][nx] = cost;
            }
        }

        cout << "Problem " << problem++ << ": " <<  dist[n-1][n-1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
