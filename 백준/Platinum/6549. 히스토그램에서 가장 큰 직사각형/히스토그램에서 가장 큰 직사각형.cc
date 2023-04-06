#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<long long> height;

long long GetMaxSize(int left, int right) {
    if (left == right) return height[left];

    int mid = (left + right) / 2;
    
    long long ret = max(GetMaxSize(left, mid), GetMaxSize(mid+1, right));

    int lo = mid, hi = mid+1;
    long long temp_height = min(height[lo], height[hi]);
    ret = max(ret, temp_height * 2);
    while (left < lo || hi < right) {
        if (hi < right && (lo == left || height[lo-1] < height[hi+1])) {
            hi++;
            temp_height = min(temp_height, height[hi]);
        } else {
            lo--;
            temp_height = min(temp_height, height[lo]);
        }
        ret = max(ret, temp_height * (hi-lo+1));
    }
    return ret;
}

void Solve() {
    while (true) {
        cin >> n;

        if (n == 0) return;

        height.clear();
        for (int i=0; i<n; i++) {
            int s;
            cin >> s;
            height.push_back(s);
        }

        long long result = GetMaxSize(0, n-1);
        cout << result << "\n";
    }
}

int main() {
    Solve();
    return 0;
}
