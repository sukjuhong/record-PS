#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
ll facto[4000001];

ll Pow(ll x, int y) {
    ll ret = 1;
    while (y) {
        if (y & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return ret;
}

void Solve() {
    int m;
    cin >> m;

    facto[0] = 1;
    facto[1] = 1;
    for (int i=2; i<=4000000; i++) {
        facto[i] = facto[i-1] * i;
        facto[i] %= MOD;
    }

    for (int i=0; i<m; i++) {
        int n, k;
        cin >> n >> k;

        ll top = facto[n];
        ll bottom = facto[k] * facto[n-k] % MOD;
        cout << top * Pow(bottom, MOD-2) % MOD << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie();
    Solve();
}
