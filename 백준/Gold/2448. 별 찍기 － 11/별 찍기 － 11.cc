#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

char arr[3 * 1024][2 * 3 * 1024];

void print_arr(int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size * 2 - 1; col++)
        {
            cout << arr[row][col];
        }
        cout << "\n";
    }
}

void fill_star(int start_y, int start_x, int size)
{
    if (size == 3)
    {
        arr[start_y][start_x] = '*';
        arr[start_y + 1][start_x - 1] = '*';
        arr[start_y + 1][start_x + 1] = '*';
        for (int col = start_x - 2; col <= start_x + 2; col++)
        {
            arr[start_y + 2][col] = '*';
        }
        return;
    }

    int next_size = size / 2;
    fill_star(start_y, start_x, next_size);
    fill_star(start_y + next_size, start_x - next_size, next_size);
    fill_star(start_y + next_size, start_x + next_size, next_size);
}

void solve()
{
    int n;
    cin >> n;

    fill(&arr[0][0], &arr[3 * 1024 - 1][2 * 3 * 1024], ' ');
    fill_star(0, n - 1, n);
    print_arr(n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}