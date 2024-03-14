#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;

  stack<int> s;
  for (int i=0; i<n; i++) {
    int tmp;
    cin >> tmp;
    s.push(tmp);
  }

  ll profit = 0;
  int max_stock = s.top();
  s.pop();
  while (!s.empty()) {
    int cur_stock = s.top();
    s.pop();

    if (max_stock < cur_stock) {
      max_stock = cur_stock;
      continue;
    }

    profit += max_stock - cur_stock;
  }

  cout << profit << "\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while (t--)
    solve();
  return 0;
}