#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;

int tile_index;
int arr[129][129];

bool is_filled(int y, int x, int size) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if (arr[y+i][x+j] != 0) return true;
        }
    }
    return false;
}

void tiling(int y, int x, int size) {
    int half_size = size / 2;
    tile_index++;

    if (!is_filled(y, x, half_size)) arr[y+half_size-1][x+half_size-1] = tile_index;
    if (!is_filled(y+half_size, x, half_size)) arr[y+half_size][x+half_size-1] = tile_index;
    if (!is_filled(y, x+half_size, half_size)) arr[y+half_size-1][x+half_size] = tile_index;
    if (!is_filled(y+half_size, x+half_size, half_size)) arr[y+half_size][x+half_size] = tile_index;
    
    if (size== 2) return;

    tiling(y, x, half_size);
    tiling(y+half_size, x, half_size);
    tiling(y, x+half_size, half_size);
    tiling(y+half_size, x+half_size, half_size);
}

void solve() {
    int n;
    cin >> n;
    pair<int, int> sink;
    cin >> sink.second >> sink.first;

    int arr_size;
    arr_size = pow(2, n);

    arr[sink.first][sink.second] = -1;

    tiling(1, 1, arr_size);

    for (int i=arr_size; i>=1; i--) {
        for (int j=1; j<=arr_size; j++) {
            if (j != 1) cout << " ";
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}