#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
char arr[2187][2187];

void PrintArr() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!arr[i][j]) cout << " ";
            else cout << arr[i][j];
        }
        cout << "\n";
    }
}

void FillArr(int start_y, int start_x, int size) {
    int next_size = size / 3;

    for (int i=start_y+next_size-1; i<=start_y+next_size*2; i++) {
        arr[i][start_x+next_size-1] = '*';
        arr[i][start_x+next_size*2] = '*';
    }

    for (int j=start_x+next_size-1; j<=start_x+next_size*2; j++) {
        arr[start_y+next_size-1][j] = '*';
        arr[start_y+next_size*2][j] = '*';
    }

    if (size == 3) return;

    FillArr(start_y, start_x, next_size);
    FillArr(start_y, start_x+next_size, next_size);
    FillArr(start_y, start_x+next_size*2, next_size);
    FillArr(start_y+next_size, start_x, next_size);
    FillArr(start_y+next_size, start_x+next_size*2, next_size);
    FillArr(start_y+next_size*2, start_x, next_size);
    FillArr(start_y+next_size*2, start_x+next_size, next_size);
    FillArr(start_y+next_size*2, start_x+next_size*2, next_size);
}

void Solve() {
    cin >> n;

    FillArr(0, 0, n);

    PrintArr();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
