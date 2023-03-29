#include <iostream>
#include <queue>
using namespace std;

int parent[20001];
int dist[20001];
queue<int> q;

int union_find(int x) {
    if (x == parent[x]) return x;
    int top_parent = union_find(parent[x]);
    dist[x] += dist[parent[x]];
    return parent[x] = top_parent;
}

void solve() {
    for (int i=1; i<=20000; i++) {
        parent[i] = i;
        dist[i] = 0;
    }

    int n;
    cin >> n;

    char cmd;
    while (true) {
        cin >> cmd;

        if (cmd == 'E') {
            int I;
            cin >> I;
            union_find(I);
            cout << dist[I] << "\n";
        } else if (cmd == 'I') {
            int I, J;
            cin >> I >> J;
            parent[I] = J;
            dist[I] = abs(I-J) % 1000;
        } else break;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();
    return 0;
}