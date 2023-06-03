#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int prefix_sum[250001];

void solve() {
    int n, x;
    cin >> n >> x;

    int sum = 0;
    for (int i=1; i<=n; i++) {
        int temp;
        cin >> temp;
        sum += temp;
        prefix_sum[i] = sum;
    }

    int result = 0;
    int cnt = 1;
    int lo = 0, hi = x;
    while (hi <= n) {
        int tmp = prefix_sum[hi] - prefix_sum[lo];
        if (result < tmp) {
            result = tmp;
            cnt = 1;
        } else if (result == tmp) {
            cnt++;
        }
        lo++; hi++;
    }

    if (result == 0) {
        cout << "SAD" << '\n';
    }
    else {
        cout << result << '\n';
        cout << cnt << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}