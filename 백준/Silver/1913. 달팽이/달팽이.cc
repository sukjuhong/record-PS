#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};
int arr[999][999];

void Solve() {
    int n, target;
    cin >> n >> target;

    int d = UP;
    int offset = 1;
    int current_y = n/2, current_x = n/2;
    int current_num = 1;
    arr[current_y][current_x] = current_num;
    current_num++;
    while (current_num <= n*n) {
        for (int i=1; i<=offset; i++) {
            if (d == UP) {
                current_y++;
            } else if (d == RIGHT) {
                current_x++;
            } else if (d == DOWN) {
                current_y--;
            } else {
                current_x--;
            }
            arr[current_y][current_x] = current_num;
            current_num++;
        }
        d = (d + 1) % 4;
        if (d == DOWN || d == UP) offset++;
    }

    int target_y = 0, target_x = 0;
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<n; j++) {
            if (j != 0) cout << " ";
            cout << arr[i][j];
            if (arr[i][j] == target) {
                target_y = i;
                target_x = j;
            }
        }
        cout << "\n";
    }
    cout << n-target_y << " " << target_x+1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
