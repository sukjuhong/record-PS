#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gears[4];
const int LEFT = 0b00000010;
const int RIGHT = 0b00100000;
const int HEAD = 0b10000000;

void rotate_gear_clockwise(int idx) {
  bool check = gears[idx] & 1;
  gears[idx] >>= 1;
  if (check) gears[idx] |= HEAD;
}

void rotate_gear_counterclockwise(int idx) {
  bool check = gears[idx] & HEAD;
  gears[idx] <<= 1;
  if (check) gears[idx] |= 1;
}

void rotate_gear(int idx, int d) {
  if (d > 0)
    rotate_gear_clockwise(idx);
  else
    rotate_gear_counterclockwise(idx);
}

int masking(int idx, int mask) {
  return (gears[idx] & mask) ? 1 : 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 4; i++) {
    string s;
    cin >> s;
    gears[i] = stoi(s, 0, 2);
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int idx, d;
    cin >> idx >> d;

    bool x = false, y = false, z = false;

    switch (idx - 1) {
      case 0:
        if (masking(0, RIGHT) != masking(1, LEFT)) {
          x = masking(1, RIGHT) != masking(2, LEFT);
          y = x && (masking(2, RIGHT) != masking(3, LEFT));
          rotate_gear(1, -d);
          if (x) rotate_gear(2, d);
          if (y) rotate_gear(3, -d);
        }
        rotate_gear(0, d);
        break;
      case 1:
        x = masking(0, RIGHT) != masking(1, LEFT);
        y = masking(1, RIGHT) != masking(2, LEFT);
        z = y && (masking(2, RIGHT) != masking(3, LEFT));
        rotate_gear(1, d);
        if (x) rotate_gear(0, -d);
        if (y) rotate_gear(2, -d);
        if (z) rotate_gear(3, d);
        break;
      case 2:
        x = masking(1, RIGHT) != masking(2, LEFT);
        y = masking(2, RIGHT) != masking(3, LEFT);
        z = x && (masking(0, RIGHT) != masking(1, LEFT));
        rotate_gear(2, d);
        if (x) rotate_gear(1, -d);
        if (y) rotate_gear(3, -d);
        if (z) rotate_gear(0, d);
        break;
      case 3:
        if (masking(2, RIGHT) != masking(3, LEFT)) {
          x = masking(1, RIGHT) != masking(2, LEFT);
          y = x && (masking(0, RIGHT) != masking(1, LEFT));
          rotate_gear(2, -d);
          if (x) rotate_gear(1, d);
          if (y) rotate_gear(0, -d);
        }
        rotate_gear(3, d);
        break;
      default:
        break;
    }
  }

  int sum_score = 0;
  for (int i = 0; i < 4; i++) {
    bool check = gears[i] & HEAD;
    sum_score += check * pow(2, i);
  }
  cout << sum_score << "\n";
  return 0;
}