#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int MOD = 1000000007;

long long pow(long long x, int y) {
    long long ret = 1;
    while (y) {
        if (y & 1)
            ret = ret * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ret;
}

int gcd(int l, int r) {
    if (r == 0)
        return l;
    return gcd(r, l % r);
}

void solve() {
    int m;
    cin >> m;

    long long sum = 0;
    for (int i = 0; i < m; i++) {
        int n, s;
        cin >> n >> s;

        int gcd_ns = gcd(n, s);
        n /= gcd_ns;
        s /= gcd_ns;

        if (n == 1) {
            cout << s << "\n";
            continue;
        }

        int temp = s * pow(n, MOD - 2) % MOD;
        sum = (sum + temp) % MOD;
    }
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}