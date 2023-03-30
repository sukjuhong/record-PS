#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> arr;
vector<int> output;
bool visited[8];

void perm(int depth, int n, int r) {
    if (depth == r) {
        for (int i=0; i<r; i++) {
            if (i != 0) cout << " ";
            cout << output[i];
        }
        cout << "\n";
    }

    int last = -1;
    for (int i=0; i<n; i++) {
        if (!visited[i] && last != arr[i]) {
            visited[i] = true;
            last = arr[i];
            output.push_back(arr[i]);
            perm(depth+1, n, r);
            visited[i] = false;
            output.pop_back();
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());
    perm(0, n, m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}