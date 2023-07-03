#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

bool recur(string& s, string t) {
    if (s == t) return true;

    if (s.length() > t.length()) return false;

    bool flag = false;
    string tmp_str;
    if (t.back() == 'A') {
        tmp_str = t;
        tmp_str.pop_back();
        flag |= recur(s, tmp_str);
    }
    
    if (t.front() == 'B') {
        tmp_str = t;
        reverse(tmp_str.begin(), tmp_str.end());
        tmp_str.pop_back();
        flag |= recur(s, tmp_str);
    }
    
    return flag;
}

void solve() {
    string s, t;
    cin >> s >> t;

    cout << recur(s, t) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}