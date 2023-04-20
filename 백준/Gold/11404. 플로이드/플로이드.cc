#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define endl "\n"

const int MAX = 0x0fffffff;
int arr[101][101];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++)
            arr[i][j] = MAX;
        arr[i][i] = 0;
    }

    for (int i=1; i<=m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        if (arr[from][to] > cost)
            arr[from][to] = cost;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (j != 1) cout << " ";
            if (arr[i][j] == MAX) arr[i][j] = 0;
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}