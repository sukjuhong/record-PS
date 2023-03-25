#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[100001];
pair<int, int> arr[101];

void doDp(int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 1; j--) {
            if (arr[i].first <= j) {
                dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].second);
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;

        arr[i] = {weight, value};
    }

    doDp(n, k);

    cout << dp[k];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}