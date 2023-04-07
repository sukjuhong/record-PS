#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Target {
    int max_health;
    int cur_health;
};

int n, k;
Target board[8][8];
vector<int> bullet;
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, 1, -1, 0};

int Shoot(int col, int damage, Target board[8][8]) {
    for (int i=0; i<n; i++) {
        if (board[col][i].cur_health == 0) continue;
        else if (board[col][i].cur_health >= 10) {
            board[col][i].cur_health = 0;
            return board[col][i].max_health;
        } else {
            if (board[col][i].cur_health <= damage) {
                board[col][i].cur_health = 0;
                for (int j=0; j<4; j++) {
                    int ny = col + dy[j];
                    int nx = i + dx[j];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                    if (!board[ny][nx].cur_health) {
                        int temp_health = board[col][i].max_health / 4;
                        board[ny][nx].max_health = board[ny][nx].cur_health = temp_health;
                    }
                }
                return board[col][i].max_health;
            } else {
                board[col][i].cur_health -= damage;
                return 0;
            }
        }
    }
    return 0;
}

int ReculsiveShooting(Target board[8][8], int cnt) {
    if (bullet.size() == cnt) return 0;

    int ret = 0;

    for (int i=0; i<n; i++) {
        Target copy_board[8][8];
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                copy_board[j][k] = board[j][k];
            }
        }
        int score = Shoot(i, bullet[cnt], copy_board);
        ret = max(ret, score + ReculsiveShooting(copy_board, cnt+1));
    }
    return ret;
}

void Solve() {
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> board[i][j].max_health;
            board[i][j].cur_health = board[i][j].max_health;
        }
    }

    for (int i=0; i<k; i++) {
        int damage;
        cin >> damage;
        bullet.push_back(damage);
    }

    int result = ReculsiveShooting(board, 0);
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    Solve();
    return 0;
}
