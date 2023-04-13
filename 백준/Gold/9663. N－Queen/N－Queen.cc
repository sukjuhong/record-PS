#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, result;
int board[15];

bool CanFill(int col) {
    for (int i=0; i<col; i++) {
        if (board[col] == board[i] || col - i == abs(board[col] - board[i])) return false;
    }
    return true;
}

void FillBoard(int col) {
    if (col == n) {
        result++;
        return;
    }

    for (int i=0; i<n; i++) {
        board[col] = i;
        if (CanFill(col)) {
            FillBoard(col+1);
        }
    }
}

void Solve() {
    cin >> n;

    FillBoard(0);
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
