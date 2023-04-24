#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// 4bytes * 100001 * 2 = 800KB
int dist[100001];
int gas[100001];

void Solve() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> dist[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> gas[i];
    }

    int total_cost = 0;
    int cur_pointer = gas[1];
    for (int i = 2; i <= n; i++) {
        total_cost += dist[i] * cur_pointer;
        if (cur_pointer > gas[i])
            cur_pointer = gas[i];
    }
    cout << total_cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
}
