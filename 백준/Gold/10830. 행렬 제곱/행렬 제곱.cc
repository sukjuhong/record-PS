#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long ll;

int n;
ll m;
const int MOD = 1000;

void PrintMatrix(ll **m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j != 0) cout << " ";
            cout << m[i][j];
        }
        cout << "\n";
    }
}

ll** ProductMatrix(ll** a, ll** b) {
    ll** ret;
    ret = new ll*[n];
    for (int i=0; i<n; i++) {
        ret[i] = new ll[n];
        memset(ret[i], 0, n*sizeof(ll));
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                ret[i][j] += a[i][k] * b[k][j] % MOD;    
                ret[i][j] %= MOD;
            }
        }
    }

    return ret;
}

ll** Pow(ll** matrix, ll x) {
    ll** ret;
    ret = new ll*[n];
    for (int i=0; i<n; i++) {
        ret[i] = new ll[n];
        ret[i][i] = 1;
    }

    while (x) {
        if (x & 1) ret = ProductMatrix(ret, matrix);
        matrix = ProductMatrix(matrix, matrix);
        x >>= 1;
    }

    return ret;
}

void Solve() {
    cin >> n >> m;

    ll** matrix = new ll*[n];
    for (int i=0; i<n; i++) matrix[i] = new ll[n];
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }

    ll** result = Pow(matrix, m);
    PrintMatrix(result);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
