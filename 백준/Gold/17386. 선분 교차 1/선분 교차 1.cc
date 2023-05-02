#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int get_ccw(pii x, pii y, pii z) {
    long long result = (y.first - x.first) * (z.second - x.second) -
                       (z.first - x.first) * (y.second - x.second);
    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    else
        return 0;
}

void Solve() {
    pair<pii, pii> l;
    pair<pii, pii> r;

    cin >> l.first.first >> l.first.second >> l.second.first >> l.second.second;
    cin >> r.first.first >> r.first.second >> r.second.first >> r.second.second;

    int result_a = get_ccw(l.first, l.second, r.first) *
                   get_ccw(l.first, l.second, r.second);
    int result_b = get_ccw(r.first, r.second, l.first) *
                   get_ccw(r.first, r.second, l.second);
    cout << (result_a <= 0 && result_b <= 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();
    return 0;
}