#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> matrix;

int square(int x) {
    return x * x;
}

void solve() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        matrix.push_back(tmp);
    }

    int min_cost = INT32_MAX;
    for (int i=0; i<=100-17; i++) {
        int tmp_cost = 0;
        for (int j=0; j<n; j++) {
            if (matrix[j] < i) tmp_cost += square(i - matrix[j]);
            else if (matrix[j] > i + 17) tmp_cost += square(matrix[j] - (i + 17));
        }
        min_cost = min(min_cost, tmp_cost);
    }
    cout << min_cost << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}