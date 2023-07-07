#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <memory.h>
using namespace std;

unordered_map<int, bool> um;

void solve() {
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        um[tmp] = true;
    }

    int m;
    cin >> m;

    for (int i=0; i<m; i++) {
        int tmp;
        cin >> tmp;
        cout << um[tmp] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}