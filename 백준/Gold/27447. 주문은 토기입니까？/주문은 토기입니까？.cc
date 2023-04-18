#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> come_time;

void Solve() {
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        come_time.push_back(temp);
    }
    
    int soon_come = 0;
    int prepare_come = 0;
    int num_togi = 0;
    int num_filled_togi = 0;
    for (int time=0; time<=1000000; time++) {
        if (come_time[soon_come] == time) {
            if (!num_filled_togi) {
                cout << "fail" << "\n";
                return;
            }
            num_filled_togi--;
            soon_come++;
        } else if (come_time[prepare_come] <= time + m) {
            if (!num_togi) {
                num_togi++;
                continue;
            }
            num_togi--;
            num_filled_togi++;
            prepare_come++;
            if (prepare_come == come_time.size()) break;
        } else num_togi++;
    }
    cout << "success" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
