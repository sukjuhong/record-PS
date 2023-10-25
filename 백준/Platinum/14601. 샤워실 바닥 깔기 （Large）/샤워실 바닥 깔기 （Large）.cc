#include <bits/stdc++.h>
using namespace std;

#define MAX 129

int arr[MAX][MAX];
int num_tile = 0;

bool is_filled(int row, int col, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (arr[row + i][col + j] != 0)
                return true;
    return false;
}

void tromino(int n, int row, int col)
{
    int half_n = n / 2;
    num_tile++;

    if (!is_filled(row, col, half_n))
        arr[row + half_n - 1][col + half_n - 1] = num_tile;
    if (!is_filled(row + half_n, col, half_n))
        arr[row + half_n][col + half_n - 1] = num_tile;
    if (!is_filled(row, col + half_n, half_n))
        arr[row + half_n - 1][col + half_n] = num_tile;
    if (!is_filled(row + half_n, col + half_n, half_n))
        arr[row + half_n][col + half_n] = num_tile;

    if (n == 2)
        return;

    tromino(half_n, row, col);
    tromino(half_n, row + half_n, col);
    tromino(half_n, row, col + half_n);
    tromino(half_n, row + half_n, col + half_n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    int n = pow(2, k);

    int x, y;
    cin >> x >> y;
    arr[y][x] = -1;

    tromino(n, 1, 1);

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}