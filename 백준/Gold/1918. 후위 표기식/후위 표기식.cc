#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
#include <unordered_map>
using namespace std;

stack<char> s;

void Solve() {
    string exp;
    cin >> exp;

    for (int i=0; i<exp.size(); i++) {
        if ('A' <= exp[i] && exp[i] <= 'Z') {
            cout << exp[i];
        } else if (exp[i] == '+' || exp[i] == '-') {
            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.push(exp[i]);
        } else if (exp[i] == '*' || exp[i] == '/') {
            while (!s.empty() && s.top() != '(' && s.top() != '+' && s.top() != '-' ) {
                cout << s.top();
                s.pop();
            }
            s.push(exp[i]);
        } else if (exp[i] == ')') {
            while (s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.pop();
        } else {
            s.push(exp[i]);
        }
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    Solve();
    return 0;
}
