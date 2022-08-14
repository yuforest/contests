// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_a
// oj t
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int L1, R1, L2, R2;
  cin >> L1 >> R1 >> L2 >> R2;
  int ans = 0;
  bool is_red = false;
  bool is_blue = false;
  for(int i = 0; i <= 100; i++) {
    if (L1 < i && i <= R1) {
      is_red = true;
    } else {
      is_red = false;
    }
    if (L2<i && i<= R2) {
      is_blue = true;
    } else {
      is_blue = false;
    }
    if (is_red && is_blue) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}