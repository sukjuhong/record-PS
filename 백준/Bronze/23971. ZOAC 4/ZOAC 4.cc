#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

void solve() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;

    int num_row = w % (m+1) == 0 ? w / (m+1) : w / (m+1) + 1;
    int num_col = h % (n+1) == 0 ? h / (n+1) : h / (n+1) + 1;
    cout << num_row * num_col << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}