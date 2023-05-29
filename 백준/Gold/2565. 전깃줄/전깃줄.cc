#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
int cache[101];
vector<pair<int, int>> arr;

int count_line(int start) {
    int &ret = cache[start+1];
    if (ret) return ret;

    ret = 1;
    for (int next=start+1; next<n; next++) {
        if (start == -1 || arr[start].second < arr[next].second)
            ret = max(ret, count_line(next) + 1);
    }
    return ret;
}

void solve() {
    cin >> n;

    for (int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        arr.push_back({l, r});
    }

    sort(arr.begin(), arr.end());

    cout << n - (count_line(-1) - 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}