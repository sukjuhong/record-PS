#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl "\n"

using ll=long long;

void update(ll* arr, ll* data, int size, int idx, ll val) {
    ll delta_val = val - arr[idx];
    arr[idx] = val;

    while (idx <= size) {
        data[idx] += delta_val;
        idx += (idx & -idx);
    }
}

ll sum(ll* data, int idx) {
    ll ret = 0;
    while (idx) {
        ret += data[idx];
        idx &= idx - 1;
    }
    return ret;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
  
    ll arr[n + 1] = {0,};
    ll data[n + 1] = {0,};

    for (int i=1; i<=n; i++) {
        ll temp;
        cin >> temp;
        update(arr, data, n, i, temp);
    }

    for (int i=1; i<=m+k; i++) {
        int cmd;
        ll l, r;
        cin >> cmd >> l >> r;

        if (cmd == 1) {
            update(arr, data, n, l, r);
        } else {
            cout << sum(data, r) - sum(data, l - 1) << endl;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}