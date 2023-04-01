#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

string cache[101][101];

string bigint_add(string a, string b) {
    int sum = 0;
    string result = "";
    while (!a.empty() || !b.empty() || sum) {
        if (!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        result.push_back((sum%10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string comb(int n, int m) {
    if (n == m || m == 0) return "1";
    
    string &ret = cache[n][m];
    if (!ret.empty()) return ret;

    return ret = bigint_add(comb(n-1, m), comb(n-1, m-1));
}

void solve() {
    int n, m;
    cin >> n >> m;

    cout << comb(n, m) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}