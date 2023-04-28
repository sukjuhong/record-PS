#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> arr[50];
bool is_know[51];
int parent[51];

int union_find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = union_find(parent[x]);
}

void union_merge(int l, int r) {
    int pl = union_find(l);
    int pr = union_find(r);
    if (!is_know[pl] && is_know[pr]) {
        union_merge(pr, pl);
        return;
    }
    if (pl != pr) {
        parent[pr] = pl;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int num_know;
    cin >> num_know;
    for (int i = 0; i < num_know; i++) {
        int temp;
        cin >> temp;
        is_know[temp] = true;
    }

    for (int i = 0; i < m; i++) {
        int num_people_in_party;
        cin >> num_people_in_party;
        for (int j = 0; j < num_people_in_party; j++) {
            int temp;
            cin >> temp;
            arr[i].push_back(temp);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < arr[i].size() - 1; j++) {
            union_merge(arr[i][j], arr[i][j + 1]);
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        bool check = true;
        for (int j = 0; j < arr[i].size(); j++) {
            parent[arr[i][j]] = union_find(parent[arr[i][j]]);
            if (is_know[parent[arr[i][j]]]) {
                check = false;
                break;
            }
        }
        count += check;
    }
    cout << count << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
