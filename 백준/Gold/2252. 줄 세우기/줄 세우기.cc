#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

queue<int> q;
vector<int> arr[32001];
int depth[32001];

void Solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        arr[l].push_back(r);
        depth[r]++;
    }

    for (int i = 1; i <= n; i++) {
        if (depth[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int cur_num = q.front();
        q.pop();
        cout << cur_num << " ";
        for (int i = 0; i < arr[cur_num].size(); i++) {
            int next_num = arr[cur_num][i];
            depth[next_num]--;
            if (depth[next_num] == 0) {
                q.push(next_num);
            }
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
}
