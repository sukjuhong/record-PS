#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Person {
    int height;
    int cnt;
};
stack<Person> s;

void Solve() {
    int n;
    cin >> n;

    long long cnt_pair = 0;

    for (int i=0; i<n; i++) {
        Person temp;
        cin >> temp.height;
        temp.cnt = 1;

        while (!s.empty() && s.top().height < temp.height) {
            cnt_pair += s.top().cnt;
            s.pop();
        }

        if (!s.empty()) {
            if (s.top().height == temp.height) {
                if (s.size() > 1) cnt_pair++;
                cnt_pair += s.top().cnt;
                temp.cnt = s.top().cnt+1;
                s.pop();
            } else {
                cnt_pair++;
            }
        }
        s.push(temp);
    }

    cout << cnt_pair << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Solve();
    return 0;
}