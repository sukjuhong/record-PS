#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

void Solve() {
    string s;
    cin >> s;

    for (int i=0; i<s.size(); i++) {
        if ('a' <= s[i] && s[i] <= 'z') s[i] += 'A' - 'a';
        else s[i] -= 'A' - 'a';
    }
    
    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
