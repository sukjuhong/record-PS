#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int D(int n) {
    return (n*2)%10000;
}

int S(int n) {
    if (n == 0) return 9999;
    return n-1;
}

int L(int n) {
    int dn[4] = {0, 0, 0, 0};
    for (int i=0; i<4; i++) {
        dn[i] = n % 10;
        n /= 10;
    }
    return ((dn[2]*10 + dn[1]) * 10 + dn[0]) * 10 + dn[3];
}

int R(int n) {
    int dn[4] = {0, 0, 0, 0};
    for (int i=0; i<4; i++) {
        dn[i] = n % 10;
        n /= 10;
    }
    return ((dn[0]*10 + dn[3]) * 10 + dn[2]) * 10 + dn[1];
}

int (*dslr[4])(int) = {D, S, L, R};
const char cmd[4] = {'D', 'S', 'L', 'R'};
queue<pair<int, string>> q;
bool visited[10000];

void solve() {
    while (!q.empty()) {
        q.pop();
    }
    fill(visited, visited+10000, false);
    
    int a, b;
    cin >> a >> b;

    q.push({a, ""});
    visited[a] = true;
    while (!q.empty()) {
        pair<int, string> node = q.front();
        int ca = node.first;
        string cb = node.second;
        q.pop();

        if (ca == b) {
            cout << cb << endl;
            return;
        }

        for (int i=0; i<4; i++) {
            int na = dslr[i](ca);
            if (!visited[na]) {
                q.push({na, cb+cmd[i]});
                visited[na] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}