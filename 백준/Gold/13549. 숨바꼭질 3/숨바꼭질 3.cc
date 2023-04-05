#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <memory.h>
using namespace std;

bool visited[100001];
deque<pair<int, int>> deq;

void Solve() {
    int n, k;
    cin >> n >> k;

    deq.push_back({n, 0});
    visited[n] = true;
    int min_time = INT32_MAX;
    while (!deq.empty()) {
        int cur_pos = deq.front().first;
        int cur_time = deq.front().second;
        deq.pop_front();

        if (cur_pos == k) {
            min_time = min(min_time, cur_time);
            continue;
        }

        if (cur_pos*2 >= 0 && cur_pos*2 <= 100000 && !visited[cur_pos*2]) {
            deq.push_front({cur_pos*2, cur_time});
            visited[cur_pos*2] = true;
        }
        if (cur_pos-1 >= 0 && cur_pos-1 <= 100000 && !visited[cur_pos-1]) {
            deq.push_back({cur_pos-1, cur_time+1});
            visited[cur_pos-1] = true;
        }
        if (cur_pos+1 >= 0 && cur_pos+1 <= 100000 && !visited[cur_pos+1]) {
            deq.push_back({cur_pos+1, cur_time+1});
            visited[cur_pos+1] = true;
        }
        
    }

    cout << min_time << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Solve();
    return 0;
}
