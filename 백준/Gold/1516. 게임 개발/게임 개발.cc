#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Comp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

vector<int> child[501];
int t[501], dp[501];
int depth[501];

void Solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        dp[i] = t[i];
        while (true) {
            int conn;
            cin >> conn;
            if (conn == -1)
                break;
            child[conn].push_back(i);
            depth[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (depth[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < child[node].size(); i++) {
            int c = child[node][i];
            dp[c] = max(dp[c], dp[node] + t[c]);
            depth[c]--;
            if (depth[c] == 0)
                q.push(c);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
}
