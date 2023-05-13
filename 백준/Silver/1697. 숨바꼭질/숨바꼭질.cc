#include <iostream>
#include <queue>
using namespace std;

struct node {
    int idx, time;
};

bool visited[200000];
queue<node> q;
int n, k;

bool isVaildIdx(int idx) {
    if (idx < 0 || idx >= 200000) return false;
    return !visited[idx];
}

void solve() {
    cin >> n >> k;

    visited[n] = true;
    q.push({n, 0});
    while(!q.empty()) {
        int idx = q.front().idx;
        int time = q.front().time;
        q.pop();

        if (idx == k) {
            cout << time << endl;
            break;
        }

        if (isVaildIdx(idx*2)) {
            visited[idx*2] = true;
            q.push({idx*2, time+1});
        }
        if (isVaildIdx(idx+1)) {
            visited[idx+1] = true;
            q.push({idx+1, time+1}); 
        }
        if (isVaildIdx(idx-1)) {
            visited[idx-1] = true;
            q.push({idx-1, time+1});
        }
    }
}

int main() {
    solve();
    return 0;
}