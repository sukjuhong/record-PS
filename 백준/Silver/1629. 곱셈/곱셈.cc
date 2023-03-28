#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

long long recul_pow(int a, int b, int c) {
    if (b == 1) return a % c;

    long long temp = recul_pow(a, b/2, c)%c;

    if (b % 2 == 0) return temp*temp%c;
    else return temp*temp%c*a%c;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << recul_pow(a, b, c) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}