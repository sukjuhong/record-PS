#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
ll n;

class Matrix {
private:
    ll matrix[2][2];
public:
    Matrix(initializer_list<initializer_list<ll>> temp_matrix) {
        int row_index = 0;
        for (auto& row : temp_matrix) {
            int col_index = 0;
            for (auto& col : row) {
                matrix[row_index][col_index++] = col;
            }
            row_index++;
        }
    }

    Matrix operator*(Matrix& rhs) {
        Matrix ret({
            {0, 0},
            {0, 0}
        });
        for (int i=0; i<2; i++) 
            for (int j=0; j<2; j++)
                for (int k=0; k<2; k++) {
                    ret.matrix[i][j] += this->matrix[i][k] * rhs.matrix[k][j];
                    ret.matrix[i][j] %= MOD;
                }
        return ret;
    }

    ll GetResult() {
        return this->matrix[0][1];
    }
};

void Solve() {
    cin >> n;

    Matrix x({
            {1, 1},
            {1, 0}
    });
    Matrix result({
            {1, 0},
            {0, 1}
    });
    while (n) {
        if (n & 1) result = result * x;
        x = x * x;
        n >>= 1;
    }
    cout << result.GetResult() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
