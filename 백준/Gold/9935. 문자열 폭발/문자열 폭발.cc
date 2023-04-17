#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

string stack_string;

void Solve() {
    string word, bomb;
    cin >> word >> bomb;

    for (int i=0; i<word.size(); i++) {
        stack_string += word[i];
        if (word[i] == bomb[bomb.size()-1]) {
            if (stack_string.size() >= bomb.size()) {
                bool check = true;
                for (int j=0; j<bomb.size(); j++) {
                    if (stack_string[stack_string.size()-1-j] != bomb[bomb.size()-1-j]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    for (int k=0; k<bomb.size(); k++) {
                        stack_string.pop_back();
                    }
                }
            }
        }
    }
    if (stack_string.empty()) {
        cout << "FRULA" << "\n";
        return;
    }
    cout << stack_string << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
