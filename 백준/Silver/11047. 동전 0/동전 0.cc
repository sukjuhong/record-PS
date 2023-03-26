#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int coins[10];

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        cin >> coins[i];
    }

    int cnt = 0;
    for (int i=n-1; i>=0; i--) {
        if (k >= coins[i]) {
            cnt += k / coins[i];
            k -= (k / coins[i]) * coins[i];
        }
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}