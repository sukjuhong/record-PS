#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int path[101];
queue<pair<int, int>> q;
bool visited[101];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n+m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        path[temp1] = temp2;
    }

    int result = INT32_MAX;
    visited[1] = true;
    q.push({1, 0});
    while (!q.empty()) {
        int pos = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (pos == 100) result = min(result, depth);

        for (int i=1; i<=6; i++) {
            int npos = pos+i;
            if (npos <= 100 && !visited[npos]) {
                visited[npos] = true;
                if (path[npos]) {
                    npos = path[npos];
                    visited[npos] = true;
                }
                q.push({npos, depth+1});
            }
        }
    }
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}