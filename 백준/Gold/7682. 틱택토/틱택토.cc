#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<string> arr;

bool FindTTT(string &s) {
    int l=0, r=arr.size()-1;
    while (l < r) {
        int mid = (l+r)/2;
        if (arr[mid] < s) {
            l = mid+1;
        } else if (arr[mid] > s) {
            r  = mid-1;
        } else return true;
    }
    return false;
}

bool CheckDone(string &s) {
    bool ret = false;
    for (int i=0; i<3; i++) {
        ret |= s[i*3] != '.' && s[i*3] == s[i*3+1] && s[i*3+1] == s[i*3+2];
        ret |= s[i] != '.' && s[i] == s[3+i] && s[3+i] == s[6+i];
    }
    return ret ||
        (s[0] != '.' && s[0] == s[4] && s[4] == s[8]) ||
        (s[2] != '.' && s[2] == s[4] && s[4] == s[6]);
}

void GetAllTTT(string &s, int depth, bool isO) {
    if (depth == s.length() || CheckDone(s)) {
        arr.push_back(s);
        return;
    };

    for (int i=0; i<9; i++) {
        if (s[i] == '.') {
            if (isO) {
                s[i] = 'O';
            } else {
                s[i] = 'X';
            }
            GetAllTTT(s , depth+1, !isO);
            s[i] = '.';
        }
    }
}

void Solve() {
    string dot = ".........";
    GetAllTTT(dot, 0, false);

    while (true) {
        string s;
        cin >> s;

        if (s == "end") return;

        if (find(arr.begin(), arr.end(), s) != arr.end()) cout << "valid" << "\n";
        else cout << "invalid" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
