#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

struct pos {
    int y;
    int x;
};

struct shark {
    pos _pos;
    int size;
    int exp;
};

struct fish {
    pos _pos;
    int dist;
};

struct comp {
    bool operator() (fish &a, fish &b) {
        if (a.dist == b.dist) {
            if (a._pos.y == b._pos.y) return a._pos.x > b._pos.x;
            return a._pos.y > b._pos.y;
        }
        return a.dist > b.dist;
    }
};

int arr[20][20];
int dist[20][20];
priority_queue<fish, vector<fish>, comp> pq;
queue<pos> q;
const int dy[4] = { -1, 0, 0, 1};
const int dx[4] = { 0, -1, 1, 0};

void solve() {
    int n;
    cin >> n;

    shark s;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                s = {i, j, 2, 0};
                arr[i][j] = 0;
            }
        }
    }

    int time = 0;
    while (true) {

        fill(&dist[0][0], &dist[19][20], -1);

        q.push({s._pos.y, s._pos.x});
        dist[s._pos.y][s._pos.x] = 0;

        while (!q.empty()) {
            int y = q.front().y;
            int x = q.front().x;
            q.pop();

            for (int i=0; i<4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n || arr[ny][nx] > s.size || dist[ny][nx] != -1) continue;

                dist[ny][nx] = dist[y][x] + 1;
                if (arr[ny][nx] && arr[ny][nx] < s.size) pq.push({ny, nx, dist[ny][nx]});
                q.push({ny, nx});
            }
        }

        if (pq.empty()) break;

        fish min_dist_fish = pq.top();
        while (!pq.empty()) pq.pop();
        s._pos = min_dist_fish._pos;
        s.exp++;
        arr[min_dist_fish._pos.y][min_dist_fish._pos.x] = 0;
        if (s.size == s.exp) {
            s.exp = 0;
            s.size++;
        }
        time += min_dist_fish.dist;
    }

    cout << time << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}