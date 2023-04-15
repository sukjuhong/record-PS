#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> arr;
stack<int> result;

void Recul(int l, int r) {
    if (l > r) return;
    result.push(arr[l]);
    if (l == r) return;

    int right_parent_idx = l+1;
    while (arr[right_parent_idx] < arr[l]) {
        right_parent_idx++;
        if (right_parent_idx == arr.size()) {
            right_parent_idx = -1;
            break;
        }
    }
    
    if (right_parent_idx != -1) {
        Recul(right_parent_idx, r);
        Recul(l+1, right_parent_idx-1);
    } else {
        Recul(l+1, r);
    }
}

void Solve() {
    int temp;
    while (cin >> temp) arr.push_back(temp);

    Recul(0, arr.size()-1);

    while (!result.empty()) {
        cout << result.top() << "\n";
        result.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
