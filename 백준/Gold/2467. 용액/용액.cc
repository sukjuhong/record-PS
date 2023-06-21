#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
vector<int> arr;
int min_sum = INT32_MAX, r1, r2;

void solve() {
    cin >> n;

    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    int lo = 0, hi = n-1;
    while (lo < hi) {
        if (abs(arr[lo] + arr[hi]) < min_sum) {
            min_sum = abs(arr[lo] + arr[hi]);
            r1 = arr[lo];
            r2 = arr[hi];
        }

        int tmp_sum = arr[lo] + arr[hi];
        if (tmp_sum < 0)
            lo++;
        else if (tmp_sum == 0)
            break;
        else
            hi--;
    }

    cout << r1 << ' ' << r2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}