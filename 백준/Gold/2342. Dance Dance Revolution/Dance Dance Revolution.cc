#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[100001];
int dp[5][5][100001];
int cur_pos[2] = {0, 0};
const int INF = 987654321;

int move_foot(int next) {
    if (arr[next] == 0) return 0;
    int &ret = dp[cur_pos[0]][cur_pos[1]][next];
    if (ret) return ret;

    ret = INF;
    for (int i=0; i<2; i++) {
        if (arr[next] == cur_pos[(i+1)%2]) continue;
        int temp = cur_pos[i];
        int need_power;
        if (cur_pos[i] == 0) need_power = 2;
        else if (abs(cur_pos[i] - arr[next]) == 2) need_power = 4;
        else if (cur_pos[i] == arr[next]) need_power = 1;
        else need_power = 3;

        cur_pos[i] = arr[next];
        ret = min(ret, move_foot(next+1)+need_power);
        cur_pos[i] = temp;
    }
    return ret;
}

void solve() {
    int idx = 0;
    while (true) {
        cin >> arr[idx];
        if (arr[idx] == 0) break;
        idx++;
    }

    cout << move_foot(0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}

