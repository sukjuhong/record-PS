#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<pair<int, int>> result;

void move(int N, int start, int end) { result.push_back({start, end}); }

void hanoi(int N, int start, int end, int sub) {
    if (N == 1) {
        move(1, start, end);
        return;
    }

    hanoi(N - 1, start, sub, end);
    move(N, start, end);
    hanoi(N - 1, sub, end, start);
}

void solve() {
    int n;
    cin >> n;
    hanoi(n, 1, 3, 2);

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << " " << result[i].second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
