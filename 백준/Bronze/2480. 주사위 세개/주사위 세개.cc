#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

void Solve() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c)
        printf("%d", 10000 + a*1000);
    else if (a == b || a == c)
        printf("%d", 1000 + a*100);
    else if (b == c)
        printf("%d", 1000 + b*100);
    else
        printf("%d", max(max(a, b), c)*100);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    Solve();
    return 0;
}
