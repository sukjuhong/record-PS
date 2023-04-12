#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

ll Pow(int x, int y) {
    if (y == 1) return x;

    ll half_pow = Pow(x, y/2) % MOD;
    
    if (y % 2 == 0) return half_pow * half_pow % MOD;
    else return (half_pow * half_pow % MOD) * x % MOD; 
}

ll Facto(int x) {
    ll ret = 1L;
    for (int i=1; i<=x; i++) {
        ret *= i;
        ret %= MOD;
    }
    return ret;
}

void Solve() {
    int n, m;
    cin >> n >> m;

    ll top = Facto(n);
    ll bottom = Facto(m) * Facto(n-m) % MOD;
    cout << top * Pow(bottom, MOD-2) % MOD << "\n";
}

int main() {
    Solve();
}
