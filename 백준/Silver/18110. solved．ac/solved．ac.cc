#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;

vector<int> arr;

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return;
    }

    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    float tmp = n * 0.15;
    tmp = round(tmp);

    float result = 0;
    for (int i=tmp; i<n-tmp; i++) {
        result += arr[i];
    }
    result /= n - tmp * 2;
    result = round(result);
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}