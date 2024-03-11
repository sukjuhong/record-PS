#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin >> s;

  int cur = 0;
  int result = 0;
  char bef;
  for (int i=s.size()-1; i>=0; i--) {
    if (s[i] == '(') {
      if (bef == ')') {
        result += --cur;
      } else {
        result++;
        cur--;
      } 
    } else {
      cur++;
    }
    bef = s[i];
  }
  cout << result << "\n";
  return 0;
}