#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> arr[1001];
int depth[1001];

void solve() {
    int n, m;
    cin >> n >> m;

    bool flag = false;
    for (int i=0; i<m; i++) {
        int j;
        cin >> j;
        int cur;
        cin >> cur;
        for (int k=0; k<j-1; k++) {
            int temp;
            cin >> temp;
            arr[cur].push_back(temp);
            depth[temp]++;
            cur = temp;
        }
    }

    queue<int> q;
    vector<int> result;
    for (int i=1; i<=n; i++) {
        if (depth[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        result.push_back(cur);
        for (int i=0; i<arr[cur].size(); i++) {
            int nxt = arr[cur][i];
            depth[nxt]--;
            if (depth[nxt] == 0)
                q.push(nxt);
        }
    }
    
    if (result.size() != n) {
        cout << 0 << '\n';
    } else {
        for (int i=0; i<result.size(); i++)
            cout << result[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}