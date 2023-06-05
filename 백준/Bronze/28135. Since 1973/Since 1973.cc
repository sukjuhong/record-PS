#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int result = 0;
    for (int i=0; i<n; i++) {
        string tmp = to_string(i);
        if (tmp.find("50") != string::npos) {
            result++;
        }
        result++;
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}