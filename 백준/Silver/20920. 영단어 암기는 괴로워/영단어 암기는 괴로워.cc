#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
#include <unordered_set>
using namespace std;

unordered_map<string, int> um;
vector<string> arr;

bool Comp(string a, string b) {
    if (um[a] == um[b]) {
        if (a.length() == b.length()) return a < b;
        return a.length() > b.length();
    }
    return um[a] > um[b];
}

void Solve() {
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        string temp;
        cin >> temp;
        if (temp.length() < m) continue;
        if (um.find(temp) == um.end()) {
            arr.push_back(temp);
            um[temp] = 1;
        } else um[temp]++;
    }

    sort(arr.begin(), arr.end(), Comp);

    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
