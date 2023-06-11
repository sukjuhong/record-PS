#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<string> mbti;
vector<string> cur_mbti;
unordered_map<string, int> um;
int result, max_depth = 3;

int get_dist(string a, string b) {
    int ret = 0;
    for (int i=0; i<4; i++)
        if (a[i] != b[i])
            ret++;
    return ret;
}

int get_all_dist() {
    int ret = 0;
    for (int i=0; i<3; i++) {
        for (int j=i+1; j<3; j++) {
            ret += get_dist(cur_mbti[i], cur_mbti[j]);
        }
    }
    return ret;
}

void comb_mbti(int start_idx, int depth) {
    if (depth == max_depth) {
        result = min(result, get_all_dist());
        return;
    }

    for (int i=start_idx; i<mbti.size(); i++) {
        cur_mbti.push_back(mbti[i]);
        comb_mbti(i+1, depth+1);
        cur_mbti.pop_back();
    }
}

void solve() {
    int n;
    cin >> n;

    result = INT32_MAX;
    mbti.clear();
    cur_mbti.clear();
    um.clear();

    for (int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        if (um.find(tmp) == um.end()) {
            mbti.push_back(tmp);
            um[tmp] = 1;
        } else if (um[tmp] < 3) {
            mbti.push_back(tmp);
            um[tmp]++;
        }
    }

    comb_mbti(0, 0);
    cout << result << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while (t--)
        solve();
    return 0;
}