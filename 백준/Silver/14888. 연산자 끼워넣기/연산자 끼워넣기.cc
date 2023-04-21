#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
int max_result = INT32_MIN;
int min_result = INT32_MAX;
int num_operator[4];
vector<int> arr;

void GetResult(int x, int cur) {
    if (x == n) {
        max_result = max(max_result, cur);
        min_result = min(min_result, cur);
        return;
    };
    
    for (int i=0; i<4; i++) {
        int temp_cur = cur;
        if (num_operator[i]) {
            switch (i) {
            case 0:
                temp_cur += arr[x];
                break;
            case 1:
                temp_cur -= arr[x];
                break;
            case 2:
                temp_cur *= arr[x];
                break;
            case 3:
                temp_cur /= arr[x];
                break;
            }
            num_operator[i]--;
            GetResult(x+1, temp_cur);
            num_operator[i]++;
        }
    }
}

void Solve() {
    cin >> n;

    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for (int i=0; i<4; i++) {
        int temp;
        cin >> temp;
        num_operator[i] = temp;
    }

    GetResult(1, arr[0]);
    cout << max_result << "\n";
    cout << min_result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
