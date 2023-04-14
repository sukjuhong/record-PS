#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, m;
vector<int> arr;
vector<int> result;
bool visited[10001];

void MultiComb(int depth, int start_idx) {
    if (depth == m) {
        for (int i=0; i<result.size(); i++) {
            if (i != 0) cout << " ";
            cout << result[i];
        }
        cout << "\n";
        return;
    }

    for (int i=start_idx; i<arr.size(); i++) {
        result.push_back(arr[i]);
        MultiComb(depth+1, i);
        result.pop_back();
    }
}

void Solve() {
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        if (!visited[temp]) {
            arr.push_back(temp);
            visited[temp] = true;
        }
    }

    sort(arr.begin(), arr.end());
    MultiComb(0, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
