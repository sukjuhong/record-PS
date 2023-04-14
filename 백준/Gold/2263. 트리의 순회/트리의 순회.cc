#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
int inorder[100000];
int postorder[100000];

void GetPreorder(int il, int ir, int pl, int pr) {
    if (ir < il) return;
    int current_parent = postorder[pr];
    cout << current_parent << " ";
    if (il == ir) return;

    int current_parent_idx = find(inorder+il, inorder+ir+1, current_parent) - (inorder+il);
    GetPreorder(il, il+current_parent_idx-1, pl, pl+current_parent_idx-1);
    GetPreorder(il+current_parent_idx+1, ir, pl+current_parent_idx, pr-1);
}

void Solve() {
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> inorder[i];
    }

    for (int i=0; i<n; i++) {
        cin >> postorder[i];
    }

    GetPreorder(0, n-1, 0, n-1);
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Solve();
}
